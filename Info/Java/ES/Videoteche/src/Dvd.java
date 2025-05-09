public class Dvd extends Cassetta {
    private static double prezzo;
    private int n_lingue;
    private static final int MAX_LINGUE = 5;
    private Lingue Tipolingua[];

    public Dvd(String titolo, int durata_sec) {
        super(titolo, durata_sec);
        Tipolingua = new Lingue[MAX_LINGUE];
        n_lingue = 0;
    }

    public static double getPrezzo() {
        return prezzo;
    }

    public int getN_lingue() {
        return n_lingue;
    }

    public static void setPrezzo(double prezzo) {
        Dvd.prezzo = prezzo;
    }

    public double getPrezzoScontato() {
        if (getSconto() != 0) {
            return prezzo - (prezzo * getSconto() / 100);
        } else {
            return prezzo;
        }
    }
    private int cercaLingue(Lingue l){
        int k = 0;
        int tro = -1;
        while( tro == -1 && k < n_lingue){
            if(Tipolingua[k].equals(l)){
                tro = k;
            }
            k++;
        }
        return tro;
    }

    public void add(Lingue l) {
        if (l != null && n_lingue < MAX_LINGUE && cercaLingue(l) == -1) {
            Tipolingua[n_lingue] = l;
            n_lingue++;
        }
    }

    public String getLingue() {
        String s = "";
        for (int k = 0; k < n_lingue; k++) {
            s = s + Tipolingua[k];
        }
        return s;
    }

    public String toString() {
        return "Prezzo " + prezzo + " Numero lingue: " + n_lingue + " lingue: " + getLingue() + "\n";
    }
}
