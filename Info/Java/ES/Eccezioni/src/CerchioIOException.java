import java.io.IOException;

public class CerchioIOException extends IOException{ 
    private float raggio;

    public CerchioIOException() {
        raggio = 0;
    }

    /*
     * le eccezioni fanno parte assieme agli errori della classe Throwable
     * gli errori non sono controllabili mentre le eccezioni sì
    */

    public CerchioIOException(float raggio) {
        this(); // invoca il costruttore senza parametri
        try {
            setRaggio(raggio);
        } catch (ValoreNonValido e) {
            System.out.println(e.getMessage());
        }
    }

    public float getRaggio() {
        return raggio;
    }

    public void setRaggio(float raggio) throws ValoreNonValido { //specifica che questo metodo va controllato
        if (raggio >= 0)
            this.raggio = raggio;
        else
            throw new ValoreNonValido("Raggio negativo"); // throw solleva una nuova eccezione
    }
}
