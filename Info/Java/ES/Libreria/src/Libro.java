public class Libro {
    private String titolo;
    private String autore;
    private Generi genere;
    private int n_pag;
    private float prezzo;
    private static final float DEF_PREZZO = 15;
    private static final int DEF_PAGINE = 200;

    public Libro(String titolo, String autore, Generi genere, int n_pag, float prezzo) {
        this.titolo = titolo;
        this.autore = autore;
        this.genere = genere;
        this.n_pag = (n_pag < 0) ? DEF_PAGINE : n_pag;
        this.prezzo = (prezzo < 0) ? DEF_PREZZO : prezzo;
    }

    public String getTitolo() {
        return titolo;
    }

    public String getAutore() {
        return autore;
    }

    public Generi getGenere() {
        return genere;
    }

    public int getN_pag() {
        return n_pag;
    }

    public float getPrezzo() {
        return prezzo;
    }

    public void setPrezzo(float prezzo) {
        if (prezzo > 0){
            this.prezzo = prezzo;
        }
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public int compareTo(Libro l){
        float costop1 = this.prezzo / this.n_pag;
        float costop2 = l.getPrezzo() / l.getN_pag();
        if (costop1 < costop2)
            return -1;
        else{
            if (costop1 == costop2)
                return 0;
            else 
                return 1;
        }
    }

    @Override
    public String toString() {
        return "Libro [titolo=" + titolo + ", autore=" + autore + ", genere=" + genere + ", n_pag=" + n_pag + ", prezzo="
                + prezzo + "]";
    }
}
