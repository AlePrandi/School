import requests

def main():
    base_url = 'http://127.0.0.1:5000'

    grandezza_nome = input("Nome della grandezza: ")
    stazione_nome = input("Nome della stazione: ")

    # Ottieni ID
    id_grandezza = requests.get(f"{base_url}/api/grandezza_id/{grandezza_nome}")
    id_stazione = requests.get(f"{base_url}/api/stazione_id/{stazione_nome}")

    if id_grandezza and id_stazione:
        r = requests.get(f"{base_url}/api/statistiche/{id_stazione}/{id_grandezza}")
        print("Statistiche:", r.json())
    else:
        print("Errore: grandezza o stazione non trovata.")

if __name__ == "__main__":
    main()