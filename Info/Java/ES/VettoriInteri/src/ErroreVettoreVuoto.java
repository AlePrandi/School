public class ErroreVettoreVuoto extends RuntimeException {
    public ErroreVettoreVuoto() {
        super("Errore Vettore Vuoto ");
    }

    public ErroreVettoreVuoto(String stringa) {
        super(stringa);
    }
}
