import requests
from datetime import datetime

def main():

    base_url = 'http://127.0.0.1:5000'

    grandezza_nome = input("Nome della grandezza: ")
    stazione_nome = input("Nome della stazione: ")
    valore = float(input("Valore della misura: "))
    data_ora = datetime.now().isoformat()

    id_grandezza = requests.get(f"{base_url}/api/grandezza_id/{grandezza_nome}")

    id_stazione = requests.get(f"{base_url}/api/stazione_id/{stazione_nome}")

    if id_grandezza and id_stazione:
        r = requests.post(f"{base_url}/api/inserisci_misura", json={
            "valore": valore,
            "id_grandezza": id_grandezza,
            "id_stazione": id_stazione,
            "data_ora": data_ora
        })
        print("Misura inviata:", r.json())
    else:
        print("Errore: ID non trovati")

if __name__ == "__main__":
    main()