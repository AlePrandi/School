import requests

BASE_URL = "http://localhost:5000/api/v1"

# 1. Ottieni la lista dei quartieri
def get_quartieri():
    response = requests.get(f"{BASE_URL}/quartieri")
    print("Quartieri:", response.json())

# 2. Aggiungi un nuovo quartiere
def add_quartiere(nome):
    response = requests.post(f"{BASE_URL}/quartieri", json={"nome": nome})
    print("Add Quartiere:", response.json())

# 3. Aggiungi una nuova segnalazione
def add_segnalazione(nome_quartiere, categoria, descrizione, stato=None):
    data = {
        "nome": nome_quartiere,
        "categoria": categoria,
        "descrizione": descrizione,
    }
    if stato:
        data["stato"] = stato
    response = requests.post(f"{BASE_URL}/segnalazioni", json=data)
    print("Add Segnalazione:", response.json())

# 4. Ottieni segnalazioni con filtri (stato, categoria, quartiere)
def get_segnalazioni(stato=None, categoria=None, quartiere=None):
    params = {}
    if stato: 
        params["stato"] = stato
    if categoria: 
        params["categoria"] = categoria
    if quartiere: 
        params["quartiere"] = quartiere
    response = requests.get(f"{BASE_URL}/segnalazioni", params=params)
    print("Segnalazioni:", response.json())

# 5. Modifica lo stato di una segnalazione
def patch_segnalazione(id_segnalazione, nuovo_stato):
    data = {
        "ids": id_segnalazione,
        "stato": nuovo_stato
    }
    response = requests.patch(f"{BASE_URL}/segnalazioni", json=data)
    print("Patch Segnalazione:", response.json())

# Esempi di chiamata
if __name__ == "__main__":
    get_quartieri()
    add_quartiere("Centro Storico")
    add_segnalazione("Centro Storico", "Buche stradali", "Grande buca in via Roma")
    get_segnalazioni(stato="in attesa")
    patch_segnalazione(1, "risolta")
