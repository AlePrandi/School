public class Cd extends Cassetta{
    private static double prezzo=15.0;
    private int n_brani;

    public Cd(String titolo, int durata_sec, int n_brani, int codice) {
        super(titolo, durata_sec);
        this.n_brani=n_brani;
    }

    public static double getPrezzo() {
        return prezzo;
    }

    public int getN_brani() {
        return n_brani;
    }

    public static void setPrezzo(double prezzo) {
        Cd.prezzo = prezzo;
    }
    public double getPrezzoScontato(){
        if(getSconto()!=0){
            return getPrezzo()-(getPrezzo()*getSconto()/100);
        }else{
            return getPrezzo();
        }
    }

    public String toString() {
        return "Prezzo: " + prezzo + " Numero brani: " + n_brani + "\n";
    }
}
