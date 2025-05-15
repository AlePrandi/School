from flask import Flask, request, jsonify
from flask_restful import Resource, Api
import sqlite3
import datetime
app = Flask(__name__)
api = Api(app)

# Funzione per connettersi al database
def get_db_connection():
    conn = sqlite3.connect('segnalazioni_urbane.db')
    c = conn.cursor()
    return conn, c

class Segnalazioni(Resource):
    def get(self):
        stato = request.args.get("stato")
        categoria = request.args.get("categoria")
        quartiere = request.args.get("quartiere")
        
        query = "SELECT s.id, s.categoria, s.descrizione, s.stato, s.data_ora, q.nome AS quartiere FROM segnalazioni s JOIN quartieri q ON s.id_quartiere = q.id"
        dati = []

        # Aggiungi le condizioni alla query in base ai parametri
        if stato:
            query += " WHERE s.stato = ?"
            dati.append(stato)

        if categoria:
            if stato:  # Se c'è già un filtro per stato, usiamo AND
                query += " AND s.categoria = ?"
            else:
                query += " WHERE s.categoria = ?"
            dati.append(categoria)

        if quartiere:
            if stato or categoria:  # Se ci sono già filtri, usiamo AND
                query += " AND q.nome = ?"
            else:
                query += " WHERE q.nome = ?"
            dati.append(quartiere)

        # Esegui la query
        conn, c = get_db_connection()
        c.execute(query, tuple(dati))
        segnalazioni = c.fetchall()
        conn.close()

        if segnalazioni:
            return jsonify({'segnalazioni': segnalazioni})
        else:
            return {'errore': 'Nessuna segnalazione trovata'}, 404
    def post(self):
        nome = request.json.get("nome")
        categoria = request.json.get("categoria")
        descrizione =  request.json.get("descrizione")
        stato = request.json.get("stato")
        if stato == None:
            stato = "in attesa"
        data = request.args.get("data")
        if data == None:
            data = datetime.datetime.now()
        if nome and categoria and descrizione:
            conn, c = get_db_connection()
            c.execute("SELECT id FROM quartieri WHERE nome = ?",(nome,))
            conn.commit()
            idq = c.fetchone()
            c.execute("INSERT INTO segnalazioni(id_quartiere, categoria, descrizione, stato, data_ora) VALUES(?,?,?,?,?)",(idq[0],categoria,descrizione,stato,data))
            conn.commit()
            return {"successo": "Dati caricati"}, 201 
        return {'errore': 'Caricamento non riuscito'}, 404
    def patch(self):
        ids = request.json.get("ids")
        stato = request.json.get("stato")
        if ids and stato:
            conn, c = get_db_connection()
            c.execute("UPDATE segnalazioni set stato = ? WHERE id = ?", (stato,ids))
            conn.commit()
            conn.close()
            return {"successo": "Stato modificati"}, 201 
        return {'errore': 'Modifica non riuscita'}, 404
            
class Quartieri(Resource):
    def get(self):
        conn, c = get_db_connection()
        c.execute("SELECT nome FROM quartieri")
        quartieri = c.fetchall()
        conn.close()
        if quartieri:
            quartieri_nomi = [q[0] for q in quartieri]
            return jsonify({'lista quartieri': quartieri_nomi})
        else:
            return {'errore': 'Nessun quartiere trovato'}, 404
    def post(self):
        nome = request.json.get("nome")
        if nome:
            conn, c = get_db_connection()
            c.execute("INSERT INTO quartieri(nome) VALUES(?)",(nome,))
            conn.commit()
            return {"successo": "Dati caricati"}, 201
        return {'errore': 'Caricamento non riuscito'}, 404
  
# Aggiunta delle risorse all'API
api.add_resource(Quartieri, '/api/v1/quartieri')
api.add_resource(Segnalazioni, '/api/v1/segnalazioni')

if __name__ == '__main__':
    app.run(debug=True, host='localhost')