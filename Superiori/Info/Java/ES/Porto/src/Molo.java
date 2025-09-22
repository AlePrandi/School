import java.util.Vector;

public class Molo {
    private int indice;
    private double prezzo_giorn;
    private double lung_max;
    private int progBarca;
    private double larg_max;
    private Vector<PostoBarca> barche;

    public Molo(int indice, double prezzo_giorn, double lung_max, double larg_max) {
        this.indice = indice;
        this.prezzo_giorn = prezzo_giorn;
        this.lung_max = lung_max;
        this.larg_max = larg_max;
        this.barche = new Vector<PostoBarca>();
    }

    public class PostoBarca {
        private int indice;
        private int numGiorni;
        private Barca barca;

        public PostoBarca() {
            this.indice = progBarca;
            this.numGiorni = 0; // è libero
            this.barca = null;
        }

        public int getIndice() {return indice;}

        public int getNumGiorni() {return numGiorni;}

        public Barca getBarca() {return barca;}

        public boolean isOccupato() {
            return barca != null;
        }

        public double barcaIn(Barca b, int num_Giorni){
            if (!isOccupato() && b.getLung() <= lung_max && b.getLarg() <= larg_max){
                this.barca = b;
                this.numGiorni = num_Giorni;
                return prezzo_giorn *num_Giorni;
            }else{
                //eccezione barca troppo grande
                return 0;
            }
        }

        public void barcaOut(){
            this.numGiorni = 0;
            this.barca = null;
        }
    }// Posto barca

    public int getindice() {
        return indice;
    }

    public double getPrezzo() {
        return prezzo_giorn;
    }

    public double getLung_max() {
        return lung_max;
    }

    public void passatoGiorno(){
        for (PostoBarca b : barche){
            b.numGiorni--;
        }
    }

    public double getLarg_max() {
        return larg_max;
    }
    
    public Vector<PostoBarca> getBarche() {
        return barche;
    }

    @Override
    public String toString() {
        String str = "";
        for( int i = 0; i < barche.size(); i++ ) {
            str += barche.get(i).toString() + "\n";
        }
        return "Molo: " + indice + ", Prezzo Giornaliero: " + prezzo_giorn + 
        ", lung_max: " + lung_max + ", larg_max: " + larg_max + "\n" + str;
    }

    
}
