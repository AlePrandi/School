import joblib
model = joblib.load("./marziano_model.joblib")
colore_Encoder = joblib.load("./marziano_encoder.joblib")
target_encoder = joblib.load("./marziano_encoder.joblib")
feature_scaler = joblib.load("./marziano_scaler.joblib")

marziano_test = [["rosso", 4, 10, 20, 5]]
marziano_test[0] = colore_Encoder.fit_transform(marziano_test[0])
specie_num = model.predict(feature_scaler.transform(marziano_test))
print(f"Il pinguino è un {target_encoder.inverse_transform(specie_num)[0]}")