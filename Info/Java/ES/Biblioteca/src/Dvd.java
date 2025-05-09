public class Dvd extends Articoli {
    private double durata;
    private String regista;

    public Dvd(String regista, double durata, String titolo, double valore) {
        super(titolo, valore);
        this.durata = durata;
        this.regista = regista;
    }

    public double getDurata() {
        return durata;
    }

    public String getRegista() {
        return regista;
    }

    public String getTitolo() {
        return super.getTitolo();
    }

    public double getValore() {
        return super.getValore();
    }

    @Override
    public String toString() {
        return "Dvd [durata=" + durata + ", regista=" + regista +
                ", valore=" + super.getValore() + ", titolo" + super.getTitolo() + "]";
    }
}
