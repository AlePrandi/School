public class Auto {
    private double altezza;
    private double oraIngresso;
    private int biglietto;
    private String targa;
    private PostoAuto siTrova;

    public Auto(double altezza, String targa) {
        this.altezza = altezza;
        this.targa = targa;
    }

    public void parcheggia(PostoAuto posto, double orario){
        oraIngresso = orario;
        siTrova = posto;
    }

    public double getAltezza() {
        return altezza;
    }

    public double getOraIngresso() {
        return oraIngresso;
    }

    public int getBiglietto() {
        return biglietto;
    }

    public String getTarga() {
        return targa;
    }

    public PostoAuto getSiTrova() {
        return siTrova;
    }

    @Override
    public String toString() {
        return "Auto: " + " altezza: " + altezza + " oraIngresso " + oraIngresso +
            " biglietto " + biglietto + " targa " + targa + " si trova nel posto: " + siTrova;
    }
}
