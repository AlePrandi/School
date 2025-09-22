from flask import Flask, request, jsonify
import sqlite3

app = Flask(__name__)
DB = 'meteo_db.db'

@app.route('/api/grandezza_id/<nome>', methods=['GET'])
def get_grandezza_id(nome):
    con = sqlite3.connect(DB)
    cur = con.cursor()
    cur.execute("SELECT id FROM grandezze WHERE nome = ?", (nome,))
    row = cur.fetchone()
    con.close()
    if row:
        return jsonify({'id': row[0]})
    else:
        return jsonify({'error': 'Grandezza non trovata'}), 404

@app.route('/api/stazione_id/<nome>', methods=['GET'])
def get_stazione_id(nome):
    con = sqlite3.connect(DB)
    cur = con.cursor()
    cur.execute("SELECT id FROM stazioni WHERE nome = ?", (nome,))
    row = cur.fetchone()
    con.close()
    if row:
        return jsonify({'id': row[0]})
    else:
        return jsonify({'error': 'Stazione non trovata'}), 404

@app.route('/api/inserisci_misura', methods=['POST'])
def inserisci_misura():
    data = request.json
    valore = data['valore']
    id_grandezza = data['id_grandezza']
    id_stazione = data['id_stazione']
    data_ora = data['data_ora']

    con = sqlite3.connect(DB)
    cur = con.cursor()
    cur.execute(
        "INSERT INTO misure (valore, id_grandezza, id_stazione, data_ora) VALUES (?, ?, ?, ?)",
        (valore, id_grandezza, id_stazione, data_ora)
    )
    con.commit()
    con.close()
    return jsonify({'success': True})

@app.route('/api/statistiche/<int:id_stazione>/<int:id_grandezza>', methods=['GET'])
def get_statistiche(id_stazione, id_grandezza):
    con = sqlite3.connect(DB)
    cur = con.cursor()
    cur.execute("""
        SELECT AVG(valore), MAX(valore), MIN(valore)
        FROM misure
        WHERE id_stazione = ? AND id_grandezza = ?
    """, (id_stazione, id_grandezza))
    row = cur.fetchone()
    con.close()

    if row and row[0] is not None:
        return jsonify({
            'media': row[0],
            'massimo': row[1],
            'minimo': row[2]
        })
    else:
        return jsonify({'error': 'Nessun dato disponibile'}), 404

if __name__ == '__main__':
    app.run(debug=True)
