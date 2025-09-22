public abstract class Articoli {
    private String titolo;
    private int idArticolo;
    private double valore;
    private Utente inPrestitoA;
    static int progressivoArticolo;

    public Articoli(String titolo, double valore){
        this.titolo = titolo;
        this.valore = valore;
    }

    public String getTitolo() {
        return titolo;
    }

    public int getIdArticolo() {
        return idArticolo;
    }

    public double getValore() {
        return valore;
    }

    public Utente getInPrestitoA() {
        return inPrestitoA;
    }

    public static int getProgressivoArticolo() {
        return progressivoArticolo;
    }

    
}
