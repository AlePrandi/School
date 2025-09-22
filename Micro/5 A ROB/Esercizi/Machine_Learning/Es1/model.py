import joblib
model = joblib.load("./penguin_model.joblib")
target_encoder = joblib.load("./feature_encoder.joblib")
feature_scaler = joblib.load("./feature_scaler.joblib")

pinguino_test = [[38, 15.6, 205.0, 3780.0]]
specie_num = model.predict(feature_scaler.transform(pinguino_test))
print(f"Il pinguino è un {target_encoder.inverse_transform(specie_num)[0]}")