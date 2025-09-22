import java.util.Vector;

public class Album {
    private String titolo;
    private Vector<Canzone> brani;
    
    public Album(String titolo, Canzone brano) {
        this.titolo = titolo;
        brani = new Vector<Canzone>();
        if (brano != null) {
            brani.add(brano);
        }
    }

    public Album(String titolo_album,String titolo_canzone, String autore, int durata_sec){
        this.titolo = titolo_album;
        this.brani = new Vector<Canzone>();
        Add(titolo_canzone, autore, durata_sec);
    }

    public void Add(String titolo_canzone, String autore, int durata_sec){
        brani.add(new Canzone(titolo_canzone, autore, durata_sec));
    }
    
    public String getTitolo() {
        return titolo;
    }
    
    public void addCanzone(Canzone c) {
        if (c != null) {
            brani.add(c);
        } else
            throw new NullPointerException("Non hai inserito nulla");
    }

    public String toString() {
        String str = "";
        for (int i = 0; i < brani.size(); i++) {
            str = brani.get(i).toString() + "\n";
        }
        return str;
    }

    private class CanzoneComp {
        private String titolo;
        private String autore;
        private int durata_sec;
    
        public CanzoneComp(String titolo, String autore, int durata_sec) {
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
}
