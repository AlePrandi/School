import requests
from datetime import datetime

url = "http://127.0.0.1:5000"

def nuovaSegnalazione(nomeQuartiere,categoria,descrizione,stato,data_ora=None):
    dati = {
        "nome" : nomeQuartiere, 
        "categoria" :categoria,
        "descrizione": descrizione,
        "stato" : stato,
        "data_ora" : data_ora
        }

    result = requests.post(f"{url}/api/v1/nuovaSegnalazione", json=dati)
    print(result.json())

def viewQuar():
    result = requests.get(f"{url}/api/v1/viewQuartieri")
    if result.status_code == 200:
        dati = result.json()
        print(dati)
    else:
        print("Errore")

def inserisciQuar(nome):
    dati = {"nome" : nome}
    result = requests.post(f"{url}/api/v1/addQuartiere", json=dati)
    print(result.json())

def cambiaStato(idSegnalazione):
    result = requests.get(f"{url}/api/v1/updateStato/{idSegnalazione}")
    print(result.json())

def getSegnalazioni(categoria=None, quartiere=None, stato=None):
    params = {}
    if categoria:
        params["categoria"] = categoria
    if stato:
        params["stato"] = stato
    if quartiere:
        params["quartiere"] = quartiere

    result = requests.get(f"{url}/api/v1/viewSegnalazioni", params=params)
    print(result.json())

if __name__ == "__main__":
    nomeQuartiere = "Centro"
    categoria = "illuminazione"
    descrizione = "Lampione spento vicino alla piazza"
    stato = "in attesa"
    data_ora = "2025-05-04 20:26:49"
    #data_ora = input("date e ora (%Y-%m-%d %H:%M:%S): ")

    #data_ora = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    #nuovaSegnalazione(nomeQuartiere,categoria,descrizione,stato,data_ora)
    #nuovaSegnalazione(nomeQuartiere,categoria,descrizione,stato)

    #viewQuar()
    nome = "Vialetto"
    #inserisciQuar(nome)
    #cambiaStato(4)
    #getSegnalazioni()  # tutte le segnalazioni
    #getSegnalazioni(categoria="rifiuti")
    getSegnalazioni(quartiere="Centro", stato="risolta")


import requests

BASE_URL = "http://localhost:5000"

def get(param=None):
    params = {}
    if param:
        params["param"] = param
    response = requests.get(f"{BASE_URL}/v1/", params=params)
    return response.json()

def post(dato=None):
    data = {"dato": dato}
    response = requests.post(f"{BASE_URL}/v1/", json=data)
    return response.json()

def delete():
    response = requests.delete(f"{BASE_URL}/v1/")
    return response.json()