public class Cassetta {
    private static int codice;
    private String titolo;
    private int durata_sec;
    private double sconto;
    private int n_copie;

    public Cassetta(String titolo, int durata_sec) {
        this.titolo = titolo;
        this.durata_sec = durata_sec;
        this.sconto=0;
        this.n_copie=0;
    }

    public int getCodice() {
        return codice;
    }

    public void setCodice(int codice){
        Cassetta.codice = codice;
    }

    public String getTitolo() {
        return titolo;
    }

    public int getDurata_sec() {
        return durata_sec;
    }

    public double getSconto() {
        return sconto;
    }

    public int getN_copie() {
        return n_copie;
    }

    public void setSconto(double sconto) {
        this.sconto = sconto;
    }

    public void setN_copie(int n_copie) {
        if (n_copie > 0){
            this.n_copie = n_copie;
        }
    }

    public String toString() {
       return "Codice: " + codice + " Titolo: " + titolo + " Durata: " + durata_sec + " Sconto: " + sconto + " Copie: " + n_copie;
    }
}
