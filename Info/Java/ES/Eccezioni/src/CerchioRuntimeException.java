public class CerchioRuntimeException {
    private float raggio;

    public CerchioRuntimeException() {
        raggio = 0;
    }

    /*
     * le eccezioni fanno parte assieme agli errori della classe Throwable
     * gli errori non sono controllabili mentre le eccezioni sì
    */

    public CerchioRuntimeException(float raggio) {
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
            throw new ValoreNonValidoNonControllato("Raggio negativo"); // throw solleva una nuova eccezione
    }
}
