public class Temperatura {

    private float temperatura;

    public Temperatura(float temperatura) {
        this.temperatura = temperatura;
    }

    public void setTempC(float tempC) {
        temperatura = tempC;
    }

    public float getTempC() {
        return temperatura;
    }

    public float getTempF() {
        return 32 + (9 * temperatura / 5);
    }

    public void setTempF(float tempC) {
        temperatura = getTempF();
    }

    public String toString() {
        return "Temperatura in gradi °C: " + getTempC() + "\n" + 
        "Temperatura in gradi °F: " + getTempF();
    }
}