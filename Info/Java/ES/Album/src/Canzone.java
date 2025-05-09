public class Canzone {
    private String titolo;
    private String autore;
    private int durata_sec;

    public Canzone(String titolo, String autore, int durata_sec) {
        this.titolo = titolo;
        this.autore = autore;
        this.durata_sec = durata_sec;
    }

    public String getTitolo() {
        return titolo;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public String getAutore() {
        return autore;
    }

    public void setAutore(String autore) {
        this.autore = autore;
    }

    public int getDurata_sec() {
        return durata_sec;
    }

    public void setDurata_sec(int durata_sec) {
        this.durata_sec = durata_sec;
    }

    public String toString() {
        return "Canzone: " + titolo + ", Autore: " + autore + ", Durata: " + durata_sec;
    }
}
