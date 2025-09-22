from flask import Flask, make_response, render_template, request, redirect, url_for, jsonify
import sqlite3
import hashlib
import jwt
import datetime
import RPi.GPIO as GPIO  # Libreria per controllare i GPIO del Raspberry Pi
import time

app = Flask(__name__)

DB_PATH = "./login.db"

SECRET_KEY = "secret_key"
ALGORITHM = "HS256"

# Variabile globale per la velocità dei motori
MOTOR_SPEED = 60

# Definizione dei comandi tramite ID
MOVEMENT_COMMANDS = {
    "0": "stop",             # Stop
    "1": "forward",          # Avanti
    "2": "backward",         # Indietro
    "3": "turn_right",       # Sterzata destra
    "4": "turn_left",        # Sterzata sinistra
    "5": "forward_right",    # Avanti con sterzata a destra
    "6": "forward_left",     # Avanti con sterzata a sinistra
    "7": "backward_right",   # Indietro con sterzata a destra
    "8": "backward_left"     # Indietro con sterzata a sinistra
}

class AlphaBot(object):
    def __init__(self, in1=12, in2=13, ena=6, in3=20, in4=21, enb=26, 
                 dr=16, dl=19):  # Sensori di linea digitali
        self.IN1 = in1
        self.IN2 = in2
        self.IN3 = in3
        self.IN4 = in4
        self.ENA = ena
        self.ENB = enb
        
        # Pin per sensori di linea
        self.DR = dr
        self.DL = dl

        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        # Imposta i pin come output per il controllo dei motori
        GPIO.setup(self.IN1, GPIO.OUT)
        GPIO.setup(self.IN2, GPIO.OUT)
        GPIO.setup(self.IN3, GPIO.OUT)
        GPIO.setup(self.IN4, GPIO.OUT)
        GPIO.setup(self.ENA, GPIO.OUT)
        GPIO.setup(self.ENB, GPIO.OUT)

        # Configura i pin per i sensori di linea con pull-up
        GPIO.setup(self.DR, GPIO.IN, GPIO.PUD_UP)
        GPIO.setup(self.DL, GPIO.IN, GPIO.PUD_UP)

        # Configura il PWM per il controllo della velocità dei motori
        self.PWMA = GPIO.PWM(self.ENA, 500)
        self.PWMB = GPIO.PWM(self.ENB, 500)
        self.PWMA.start(0)
        self.PWMB.start(0)

    def setMotor(self, left, right):
        # Controllo del motore destro
        if right >= 0:
            GPIO.output(self.IN3, GPIO.LOW)
            GPIO.output(self.IN4, GPIO.HIGH)
            self.PWMB.ChangeDutyCycle(right)
        elif right < 0:
            GPIO.output(self.IN3, GPIO.HIGH)
            GPIO.output(self.IN4, GPIO.LOW)
            self.PWMB.ChangeDutyCycle(abs(right))

        # Controllo del motore sinistro
        if left >= 0:
            GPIO.output(self.IN1, GPIO.HIGH)
            GPIO.output(self.IN2, GPIO.LOW)
            self.PWMA.ChangeDutyCycle(left)
        elif left < 0:
            GPIO.output(self.IN1, GPIO.LOW)
            GPIO.output(self.IN2, GPIO.HIGH)
            self.PWMA.ChangeDutyCycle(abs(left))

    def stop(self):
        self.setMotor(0, 0)
        
    def get_line_sensors(self):
        """Legge lo stato dei sensori di linea"""
        right_value = GPIO.input(self.DR)
        left_value = GPIO.input(self.DL)
        
        # Determina lo stato dei sensori
        if left_value == 0 and right_value == 0:
            status = "entrambi accesi"
        elif left_value == 0 and right_value == 1:
            status = "sinistro acceso"
        elif left_value == 1 and right_value == 0:
            status = "destro acceso"
        else:
            status = "entrambi spenti"
        
        return {
            "left": left_value, 
            "right": right_value,
            "status": status
        }

# Istanza globale del robot
bot = AlphaBot()

def get_db_connection():
    try:
        conn = sqlite3.connect(DB_PATH)
        return conn
    except sqlite3.Error as e:
        print(f"Errore durante la connessione al database: {e}")
        return None

def hash_password(password):
    """Crea un hash SHA256 della password per memorizzarla in modo sicuro."""
    return hashlib.sha256(password.encode('utf-8')).hexdigest()

def generate_token(username):
    """Genera un token JWT contenente lo username e una data di scadenza di 1 giorno"""
    payload = {
        "username": username,
        "exp": datetime.datetime.utcnow() + datetime.timedelta(days=1)
    }
    token = jwt.encode(payload, SECRET_KEY, algorithm=ALGORITHM)
    
    if isinstance(token, bytes):
        token = token.decode('utf-8')
    return token

def verify_token(token):
    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
        return payload
    except jwt.ExpiredSignatureError:
        print("Il token è scaduto.")
    except jwt.InvalidTokenError:
        print("Token non valido.")
    return None

def check_auth():
    """Funzione di utilità per verificare l'autenticazione dell'utente"""
    token = request.cookies.get('token')
    if not token:
        return None
    
    payload = verify_token(token)
    return payload

def auth_required(view_function):
    """Decoratore per richiedere l'autenticazione per una route"""
    def wrapper(*args, **kwargs):
        payload = check_auth()
        if not payload:
            if request.headers.get('Accept') == 'application/json':
                return jsonify({"error": "Autenticazione richiesta"}), 401
            else:
                return redirect(url_for('login'))
        return view_function(*args, **kwargs)
    wrapper.__name__ = view_function.__name__
    return wrapper

def control_alphabot_by_id(movement_id, state=True):
    """
    Controlla il robot in base all'ID del movimento e al suo stato.
    Se state=False, ferma il robot.
    Usa la velocità globale impostata tramite lo slider.
    """
    global MOTOR_SPEED
    
    if not state or movement_id == "0":
        print("Comando: Stop")
        bot.stop()
        return
    
    # Calcola velocità ridotta per le sterzate
    turn_speed = max(MOTOR_SPEED * 0.33, 20)
    
    # Esegui il comando in base all'ID
    if movement_id == "1":  # Avanti
        print(f"Comando: Avanti (velocità: {MOTOR_SPEED})")
        bot.setMotor(MOTOR_SPEED, MOTOR_SPEED)
    elif movement_id == "2":  # Indietro
        print(f"Comando: Indietro (velocità: {MOTOR_SPEED})")
        bot.setMotor(-MOTOR_SPEED, -MOTOR_SPEED)
    elif movement_id == "3":  # Sterzata destra
        print(f"Comando: Destra (velocità: {MOTOR_SPEED})")
        bot.setMotor(MOTOR_SPEED, -MOTOR_SPEED)
    elif movement_id == "4":  # Sterzata sinistra
        print(f"Comando: Sinistra (velocità: {MOTOR_SPEED})")
        bot.setMotor(-MOTOR_SPEED, MOTOR_SPEED)
    elif movement_id == "5":  # Avanti con sterzata a destra
        print(f"Comando: Avanti-destra (velocità: {MOTOR_SPEED})")
        bot.setMotor(MOTOR_SPEED, turn_speed)
    elif movement_id == "6":  # Avanti con sterzata a sinistra
        print(f"Comando: Avanti-sinistra (velocità: {MOTOR_SPEED})")
        bot.setMotor(turn_speed, MOTOR_SPEED)
    elif movement_id == "7":  # Indietro con sterzata a destra
        print(f"Comando: Indietro-destra (velocità: {MOTOR_SPEED})")
        bot.setMotor(-turn_speed, -MOTOR_SPEED)
    elif movement_id == "8":  # Indietro con sterzata a sinistra
        print(f"Comando: Indietro-sinistra (velocità: {MOTOR_SPEED})")
        bot.setMotor(-MOTOR_SPEED, -turn_speed)
    else:
        print(f"Comando sconosciuto: {movement_id}")
        bot.stop()

def map_key_to_movement_id(key):
    """Mappa i tasti WASD a ID di movimento per compatibilità con il codice esistente"""
    if key == 'w':
        return "1"  # avanti
    elif key == 's':
        return "2"  # indietro
    elif key == 'd':
        return "3"  # destra
    elif key == 'a':
        return "4"  # sinistra
    elif key == 'stop':
        return "0"  # stop
    return "0"  # default: stop

@app.route('/login', methods=['GET', 'POST'])
def login():
    """
    Gestisce la pagina di login.
    In caso di POST, verifica le credenziali e genera un token JWT.
    Viene impostato solo il cookie del token, poiché contiene già lo username.
    """
    if request.method == 'POST':
        username = request.form.get('e-mail')
        password = request.form.get('password')

        if not username or not password:
            return render_template('login.html', alert="Inserisci username e password!")

        password_hash = hash_password(password)

        query_login = """ 
            SELECT * 
            FROM credenziali 
            WHERE username = ? AND password = ?
        """

        conn = get_db_connection()
        if conn:
            cur = conn.cursor()
            cur.execute(query_login, (username, password_hash))
            user = cur.fetchone()
            conn.close()

        if user:
            token = generate_token(username)
            response = make_response(redirect(url_for('index')))
            response.set_cookie('token', token, max_age=60 * 60 * 24)
            print(f"Token generato: {token}")
            return response
        else:
            return render_template('login.html', alert="Credenziali non valide!")
    return render_template('login.html')

@app.route('/create_account', methods=['GET', 'POST'])
def create_account():
    if request.method == 'POST':
        username = request.form.get('e-mail')
        password = request.form.get('password')

        if not username or not password:
            return render_template('create_account.html', alert="Inserisci tutti i dati richiesti!")

        password_hash = hash_password(password)

        query_insert = """
            INSERT INTO credenziali (username, password)
            VALUES (?, ?)
        """

        conn = get_db_connection()
        if conn:
            cur = conn.cursor()
            try:
                cur.execute(query_insert, (username, password_hash))
                conn.commit()
                conn.close()
                return redirect(url_for('login'))
            except sqlite3.IntegrityError:
                conn.close()
                return render_template('create_account.html', alert="Username già esistente!")
    return render_template('create_account.html')

@app.route('/logout', methods=['POST'])
def logout():
    """Gestisce il logout cancellando il cookie del token"""
    response = make_response(redirect(url_for('login')))
    response.delete_cookie('token')
    return response

@app.route('/')
def index():
    token = request.cookies.get('token')
    if token:
        payload = verify_token(token)
        if payload:
            username = payload.get("username")
            return render_template('index.html', username=username)
    return redirect(url_for('login'))

# Manteniamo la vecchia route per compatibilità
@app.route("/key_event", methods=['POST'])
@auth_required
def key_event():
    """
    Riceve gli eventi dei tasti (premuto/rilasciato) dal client.
    Converte il tasto in un ID di movimento e passa alla nuova API.
    """
    data = request.json
    key = data.get('key')
    state = data.get('state')  # True = premuto, False = rilasciato
    
    # Converte il tasto in ID movimento
    movement_id = map_key_to_movement_id(key)
    
    # Usa la nuova funzione di controllo
    control_alphabot_by_id(movement_id, state)
    return jsonify({"success": True, "movement_id": movement_id}), 200

@app.route("/api/movement", methods=['POST'])
@auth_required
def movement_control():
    """
    API unificata per il controllo dei movimenti.
    Accetta un ID movimento e lo stato (opzionale, default=True).
    """
    data = request.json
    movement_id = data.get('movement_id')
    state = data.get('state', True)  # Default a True se non specificato
    
    if movement_id is None:
        return jsonify({"success": False, "error": "Parametro movement_id mancante"}), 400
        
    if movement_id not in MOVEMENT_COMMANDS:
        return jsonify({"success": False, "error": f"ID movimento non valido: {movement_id}"}), 400
    
    control_alphabot_by_id(movement_id, state)
    
    return jsonify({
        "success": True, 
        "movement_id": movement_id,
        "command": MOVEMENT_COMMANDS.get(movement_id, "unknown"),
        "state": state
    }), 200

@app.route("/set_speed", methods=['POST'])
@auth_required
def set_speed():
    """
    Riceve il valore della velocità dallo slider e lo salva nella variabile globale.
    Il valore viene utilizzato per il controllo dei motori.
    """
    global MOTOR_SPEED
    data = request.json
    speed = data.get('speed')
    
    if speed is not None and 20 <= speed <= 100:
        MOTOR_SPEED = speed
        print(f"Velocità motori impostata a: {MOTOR_SPEED}%")
        return jsonify({"success": True, "speed": MOTOR_SPEED}), 200
    else:
        return jsonify({"success": False, "error": "Valore velocità non valido"}), 400

@app.route("/token_info", methods=['GET'])
def token_info():
    """Mostra le informazioni del token"""
    token = request.cookies.get('token')
    if not token:
        return jsonify({"message": "Token non trovato!"}), 400

    payload = verify_token(token)
    print("Token:", token)
    print("Payload:", payload)

    return jsonify({
        "token": token,
        "payload": payload
    }), 200

# ----- ENDPOINT API PER I SENSORI -----

@app.route("/api/sensors/line", methods=['GET'])
@auth_required
def get_line_sensors():
    """Endpoint per ottenere solo i dati dei sensori di linea"""
    try:
        line_sensors = bot.get_line_sensors()
        return jsonify({
            "success": True,
            "data": line_sensors
        }), 200
    except Exception as e:
        return jsonify({
            "success": False,
            "error": str(e)
        }), 500

if __name__ == "__main__":
    robot = "0.0.0.0"
    app.run(debug=True, host=robot)