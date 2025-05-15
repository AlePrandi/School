from flask import Flask, request, jsonify
from flask_restful import Resource, Api
import sqlite3
import datetime

app = Flask(__name__)
api = Api(app)

def get_db_connection():
    conn = sqlite3.connect('./qualita_aria.db')
    c = conn.cursor()
    return conn, c

class Inquinanti(Resource):
    
    def get(self, zona_id):
        query = """SELECT i.id, i.nome, i.unita,  count(*) 
                FROM zone as z, inquinanti as i, misurazioni as m
                WHERE m.id_inquinante = i.id
                AND m.id_zona = ?
                GROUP BY i.id
                """
        conn, cur = get_db_connection()
        cur.execute(query, (zona_id, ))
        result = cur.fetchall()
        conn.close()
        dati = []
        for dato in result:
            dati.append({"id_inquinante": dato[0], "nome": dato[1], "unita": dato[2], "misure_totali": dato[3]})
        return jsonify({"risultati" : dati})
             
class Alert(Resource):
    
    def post(self):
        dati = request.json
        inquinante = dati["inquinante"]
        zona = dati["zona"]
        valore = dati["valore"]
        if dati["data"]:
            data = dati["data"]
        else:
            data = datetime.datetime.now()
            
        conn, cur = get_db_connection()
        
        cur.execute("SELECT id FROM inquinanti WHERE nome = ?", (inquinante, ))
        dato = cur.fetchone()
        id_inq = dato[0]
        cur.execute("SELECT id FROM zone WHERE nome = ?", (zona, ))
        dato = cur.fetchone()
        id_zona = dato[0]
        query = """
                INSERT INTO misurazioni(id_inquinante, id_zona, valore, data_ora) VALUES (?,?,?,?) 
                """ 
        cur.execute(query, (id_inq, id_zona, valore, data,))

        query_controllo = """
            SELECT soglia_media, soglia_massima
            FROM soglie
            WHERE id_inquinante = ?
            """
        cur.execute(query_controllo, (id_inq,))
        soglie = cur.fetchone()
        conn.close()
        soglia_med = soglie[0]
        soglia_max = soglie[1]
        print(valore, soglia_med, soglia_max)
        if valore > soglia_med:
            return {"alert": "media", "messaggio": "Soglia media supearata"}, 201
        elif valore > soglia_max:
            return {"alert": "massima", "messaggio": "Soglia massima supearata"}, 201
        else:
            return {"messaggio": "misura registrata"}, 201
    
    
class Soglie(Resource):
    def put(self, inquinante_id):
        dati = request.json
        media = dati["soglia_media"]
        massima = dati["soglia_massima"]
        
        query = """
        UPDATE soglie 
        WHERE id_inquianante = ?
        SET soglia_media = ?
        SET soglia_massima = ?
        """
        
        conn, cur = get_db_connection()
        cur.execute(query, (inquinante_id, media, massima,))
        conn.close()
        return jsonify({"messaggio" : "soglie aggiornate con successo"})
        
        
        
api.add_resource(Inquinanti, "/api/zone/<int:zona_id>/inquinanti")   
api.add_resource(Alert, "/api/alert")     
api.add_resource(Soglie, "/api/soglie/<int:inquinante_id>")     


if __name__ == '__main__':
    app.run(debug=True, host='localhost')
    
   