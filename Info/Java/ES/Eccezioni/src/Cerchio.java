public class Cerchio {
    private float raggio;

    public Cerchio() {
        raggio = 0;
    }

    /*
     * le eccezioni fanno parte assieme agli errori della classe Throwable
     * gli errori non sono controllabili mentre le eccezioni sì
    */

    public Cerchio(float raggio) {
        this(); // invoca il costruttore senza parametri
        setRaggio(raggio);
    }

    public float getRaggio() {
        return raggio;
    }

    public void setRaggio(float raggio){ //specifica che questo metodo va controllato
        if (raggio >= 0)
            this.raggio = raggio;
        else
            throw new IllegalArgumentException("Raggio negativo"); // throw solleva una nuova eccezione
    }
}
