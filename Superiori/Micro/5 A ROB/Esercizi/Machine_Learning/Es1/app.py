from flask import Flask, request, render_template_string
import joblib
import numpy as np

app = Flask(__name__)

# Caricamento dei modelli
model = joblib.load("./penguin_model.joblib")
feature_scaler = joblib.load("./feature_scaler.joblib")
target_encoder = joblib.load("./feature_encoder.joblib")

html_template = '''
<html>
<head>
    <style>
        body {font-family: Arial, sans-serif; background-color: #f0f8ff; margin: 40px;}
        h2 { color: #333366; }
        form { background-color: #ffffff; padding: 20px; border-radius: 10px; box-shadow: 0 4px 8px rgba(0,0,0,0.1); }
        input[type="text"] { margin: 10px 0; padding: 8px; width: 100%; border: 1px solid #ccc; border-radius: 4px; }
        input[type="submit"] { background-color: #333366; color: white; padding: 10px 20px; border: none; border-radius: 4px; cursor: pointer; }
        input[type="submit"]:hover { background-color: #555599; }
        h3 { color: #006600; }
    </style>
</head>
<body>
    <h2>Predizione Specie Pinguino</h2>
    <form action="/predict" method="post">
        Culmen Length (mm): <input type="text" name="culmen_length_mm" required><br>
        Culmen Depth (mm): <input type="text" name="culmen_depth_mm" required><br>
        Flipper Length (mm): <input type="text" name="flipper_length_mm" required><br>
        Body Mass (g): <input type="text" name="body_mass_g" required><br>
        <input type="submit" value="Predici">
    </form>
    {% if prediction_text %}
    <h3>{{ prediction_text }}</h3>
    {% endif %}
</body>
</html>
'''

@app.route('/', methods=['GET'])
def home():
    return render_template_string(html_template, prediction_text="")

@app.route('/predict', methods=['POST'])
def predict():
    try:
        features = [float(request.form[key]) for key in ['culmen_length_mm', 'culmen_depth_mm', 'flipper_length_mm', 'body_mass_g']]
        scaled_data = feature_scaler.transform([features])
        prediction_num = model.predict(scaled_data)
        prediction = target_encoder.inverse_transform(prediction_num)

        return render_template_string(html_template, prediction_text=f'Specie Predetta: {prediction[0]}')
    except Exception as e:
        return render_template_string(html_template, prediction_text=f'Errore: {str(e)}')

if __name__ == "__main__":
    app.run(debug=True)
