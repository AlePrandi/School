from flask import Flask, request
from flask_restful import Resource, Api
from datetime import datetime
import sqlite3


app = Flask(__name__)
api = Api(app)

PATH_DB = "./segnalazioni_urbane.db"

class NuovaSegnalazione(Resource):
    def post(self):
        dati = request.json
        if dati["nome"] and dati["categoria"] and dati["descrizione"] and dati["stato"]:
            conn = sqlite3.connect(PATH_DB)
            cur = conn.cursor()
            cur.execute("SELECT id FROM quartieri WHERE nome = ?", (dati["nome"], ))
            resultQuar = cur.fetchone()
            if not resultQuar:
                conn.close()
                return {"error":"no quartiere"}
                        
            if not dati["data_ora"]:
                data_ora = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            else:
                data_ora = dati["data_ora"]
     
            cur.execute("INSERT INTO segnalazioni(id_quartiere,categoria,descrizione,stato,data_ora) VALUES(?,?,?,?,?)", (resultQuar[0], dati["categoria"], dati["descrizione"], dati["stato"], data_ora))
            conn.commit()
            conn.close()
            return {"message": "Segnalazione inserita"}, 200
        else:
            return {"errore": "Dati mancanti"}, 400

class Quartieri(Resource):
    def get(self):
        conn = sqlite3.connect(PATH_DB)
        cur = conn.cursor()
        cur.execute("SELECT nome FROM quartieri")
        result = cur.fetchall()

        print(result)
        conn.close()

        dati = []
        for r in result:
            dati.append(r[0])
        return {"quartieri": dati}, 200
    
class Quartiere(Resource):
    def post(self):
        dati = request.json
        if dati["nome"]:
            conn = sqlite3.connect(PATH_DB)
            cur = conn.cursor()
            cur.execute("INSERT INTO quartieri(nome) VALUES(?)", (dati["nome"],))
            conn.commit()
            conn.close()
            return {"message": f"{dati['nome']} aggiunto"}, 200
        else:
            return {"errore": "Dati mancanti"}, 400


class cambiaStato(Resource):
    def get(self, idSegnalazione):
        conn = sqlite3.connect(PATH_DB)
        cur = conn.cursor()
        cur.execute("UPDATE segnalazioni SET stato = 'risolta' WHERE id = ?", (idSegnalazione,))
        conn.commit()
        conn.close()
        return {"message": f"Segnalazione {idSegnalazione} aggiornata"}, 200

class Segnalazioni(Resource):
    def get(self):
        categoria = request.args.get("categoria")
        quartiere = request.args.get("quartiere")
        stato = request.args.get("stato")
        conn = sqlite3.connect(PATH_DB)
        cur = conn.cursor()
        if categoria:
            cur.execute("SELECT id FROM segnalazioni WHERE categoria=?", (categoria,))
            result = cur.fetchall()
            conn.close()
            dati = []
            for r in result:
                dati.append(r[0])
            return {"segnalazioni(categoria)": dati}, 200
        
        elif quartiere and stato:
            cur.execute("SELECT id FROM quartieri WHERE nome=?", (quartiere,))
            idQuar = cur.fetchone()[0]
            cur.execute("SELECT id FROM segnalazioni WHERE id_quartiere=? AND stato=?", (idQuar, stato))
            result = cur.fetchall()
            conn.close()
            dati = []
            for r in result:
                dati.append(r[0])
            return {"segnalazioni(quartiere-stato)": dati}, 200
        
        else:
            cur.execute("SELECT id FROM segnalazioni")
            result = cur.fetchall()
            conn.close()
            dati = []
            for r in result:
                dati.append(r[0])
            return {"segnalazioni(tutte)": dati}, 200




api.add_resource(NuovaSegnalazione, "/api/v1/nuovaSegnalazione")
api.add_resource(Quartieri, "/api/v1/viewQuartieri")
api.add_resource(Quartiere, "/api/v1/addQuartiere")
api.add_resource(cambiaStato, "/api/v1/updateStato/<string:idSegnalazione>")
api.add_resource(Segnalazioni, "/api/v1/viewSegnalazioni")



if __name__ == "__main__":
    app.run(host="127.0.0.1")