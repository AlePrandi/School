import requests
import datetime

BASE_URL = "http://localhost:5000"


def main():
    zona = input("Inserisci la zona desiderata: ")
    inq = input("Inserisci il nome dell'inquinante: ")
    valore = float(input("Inserisci il valore della misurazione: "))
    # aggiunta per chiedere se si vuole anche data e ora
    data_ora = input("inserisci data e ora(/ per non inserire): ")
    if data_ora == "/":
        data = {"zona": zona , "inquinante": inq, "valore": valore, "data": str(datetime.datetime.now())}
    else:
        data["data"] = data_ora
        
    print(requests.post(f"{BASE_URL}/api/alert", json=data).json())
    
if __name__ == "__main__":
    main()
