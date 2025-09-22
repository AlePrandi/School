from flask import Flask, render_template, request
import joblib
import numpy as np

app = Flask(__name__)

# Caricare i modelli pre-addestrati
model = joblib.load("./fiat_model.joblib")
le_model = joblib.load("./fiat_LE_model.joblib")
le_transmission = joblib.load("fiat_LE_transmission.joblib")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        prezzo = None
    else:
        # Ottenere i dati dal form
        modello = request.form["modello"]
        trasmissione = request.form["trasmissione"]
        proprietari = int(request.form["proprietari"])
        potenza = float(request.form["potenza"])
        eta = int(request.form["eta"])
        km = float(request.form["km"])
        lat = float(request.form["lat"])
        lon = float(request.form["lon"])
        
        # Convertire le variabili categoriche
        modello_encoded = le_model.fit_transform([modello])[0]
        trasmissione_encoded = le_transmission.fit_transform([trasmissione])[0]
        
        # Creare il vettore di input
        input_data = np.array([[modello_encoded, potenza, trasmissione_encoded, eta, km, proprietari, lat, lon]])
        
        # Predire il prezzo
        prezzo = model.predict(input_data)[0]
        prezzo = round(float(prezzo), 2)
    
    return render_template("index.html", prezzo=prezzo)

if __name__ == "__main__":
    app.run(debug=True, host = "localhost")
