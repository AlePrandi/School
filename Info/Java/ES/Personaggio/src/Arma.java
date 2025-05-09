public class Arma {
    private String nome;
    private double potenza;
    private double caricaPerc;

    private static final double DEF_POT = 10.0;
    private static final double DEF_CARICA = 20.0;

    public Arma(String nome, double potenza, double caricaPerc) {
        this.nome = nome;
        this.potenza = (potenza > 0.0) ? potenza : DEF_POT;
        this.caricaPerc = (caricaPerc > 0.0) ? caricaPerc : DEF_CARICA;
    }

    public String getNome() {
        return nome;
    }

    public double getPotenza() {
        return potenza;
    }

    public double getCaricaPerc() {
        return caricaPerc;
    }

    public void setPotenza(double potenza) {
        this.potenza = potenza;
    }

    public void setCaricaPerc(double caricaPerc) {
        this.caricaPerc = caricaPerc;
    }

    @Override
    public String toString() {
        return "Arma [nome=" + nome + ", potenza=" + potenza + ", caricaPerc=" + caricaPerc + "]";
    }
}
