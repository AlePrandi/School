public class Libro extends Articoli{
    private int n_pagine;
    private String autore;

    public Libro(String autore,int n_pagine, String titolo,double valore){
        super(titolo, valore);
        this.n_pagine = n_pagine;
        this.autore = autore;
    }

    public int getN_pagine() {
        return n_pagine;
    }

    public String getAutore() {
        return autore;
    }

    public String getTitolo(){
        return super.getTitolo();
    }

    public double getValore(){
        return super.getValore();
    }

    @Override
    public String toString() {
        return "Libro [n_pagine=" + n_pagine + ", autore=" + autore +
          ", valore=" + super.getValore() + ", titolo" + super.getTitolo() + "]";
    }
}
