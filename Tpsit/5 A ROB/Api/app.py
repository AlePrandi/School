import flask

app = flask.Flask(__name__)

@app.route('/api/v1/PariDispari', methods=['GET'])
def get_pari_dispari():
    if "numero" in flask.request.args:
        numero = int(flask.request.args["numero"])
        result = ""
        try:
            numero = int(numero)
            if numero % 2 == 0:
                result = {"risultato": "pari"}
            else:
                result = {"risultato": "dispari"}
        except ValueError:
            result = {"error": "Il numero deve essere un intero."}
        return flask.jsonify(result)
    else:
        return {"error": "Nessun numero fornito."}
    
@app.route('/api/v1/NumDivisore', methods=['GET'])
def get_num_divisore():
    if "numero"  and "div" in flask.request.args:
        numero = flask.request.args["numero"]
        div = flask.request.args["div"]
        result = ""
        try:
            numero = int(numero)
            div = int(div)
            if numero % div == 0:
                result = {"risultato": "il numero è divisibile"}
            else:
                result = {"risultato": "il numero non è divisibile"}
        except ValueError:
            result = {"error": "Il numero deve essere un intero."}
        return flask.jsonify(result)
    else:
        return {"error": "Nessun numero fornito."}
    
@app.route('/')
def index():
    return "Api tutorial"
    
if __name__ == '__main__':
    app.run(debug=True, host="localhost")