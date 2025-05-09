import java.util.Vector;

public class Succursale {
    private String nome;
    private String indirizzo;
    private int progressivoScaffale;
    private Vector <Scaffale> vSaffali;


    private class Scaffale{
        private int numero;
        private Tipi tipo;
        private  static final int MAX_ARTICOLI = 25;
        private Articoli[] articoli;
        private int nArticoli;

        public Scaffale(int numero, Tipi tipo) {
            this.numero = numero;
            this.tipo = tipo;
            this.nArticoli = 0;
            this.articoli = new Articoli[MAX_ARTICOLI];
        }

        public boolean addArticoli(Articoli a){
            boolean aggiunto = false;
            if( a != null && nArticoli < MAX_ARTICOLI){
                if (a instanceof Libro && tipo == Tipi.Libro || a instanceof Dvd && tipo == Tipi.Dvd){
                    articoli[nArticoli] = a;
                    nArticoli++;
                    aggiunto = true;
                }
            }
            return aggiunto;
        }

        public int getNumero() {
            return numero;
        }

        public Tipi getTipo() {
            return tipo;
        }

        public Articoli[] getArticoli() {
            return articoli;
        }

        public int getnArticoli() {
            return nArticoli;
        }

        @Override
        public String toString() {
            return "Scaffale [numero=" + numero + ", tipo=" + tipo + ", articoli=" + toString(articoli)
                    + ", nArticoli=" + nArticoli + "]";
        }
    }

}
