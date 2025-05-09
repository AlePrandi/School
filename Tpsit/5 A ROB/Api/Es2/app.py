from flask import Flask, request, jsonify
import sqlite3
import datetime

app = Flask(__name__)

@app.route("/v1/nuova_segnalazione", methods=['POST'])
def nuova_segnalazione():
    data = request.json
    nome_quartiere = data['nome_quartiere']
    categoria = data['categoria']
    descrizione = data['descrizione']
    if data["stato"]:
        stato = data['stato']
    else:
        stato = "in attesa"
    data_segnalazione = datetime.datetime.now()

    con = sqlite3.connect('segnalazioni.db')
    cur = con.cursor()
    cur.execute("""
        INSERT INTO segnalazioni (nome_quartiere, categoria, descrizione, stato, data_segnalazione)
        VALUES (?, ?, ?, ?, ?)
    """, (nome_quartiere, categoria, descrizione, stato , data_segnalazione))
    con.commit()
    con.close()

    return jsonify({'success': True}), 201


@app.route("/v1/visualizza_segnalazioni", methods=['GET'])
def visualizza_segnalazioni():
    con = sqlite3.connect('segnalazioni.db')
    cur = con.cursor()
    cur.execute("SELECT * FROM segnalazioni")
    segnalazioni = cur.fetchall()
    con.close()
    return jsonify({"dati" : segnalazioni}), 200

@app.route("/v1/aggiungi_quartieri/", methods=['GET'])
def aggiungi_quartieri():
    pass

@app.route("/v1/aggiorna_stato", methods=['GET'])
def aggiorna_stato():
    pass

@app.route("/v1/visualizza_elencoFilt/", methods=['GET'])
def visualizza_elencoFilt():
    pass
