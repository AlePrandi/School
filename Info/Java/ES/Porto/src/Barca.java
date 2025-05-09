public class Barca {
    private String nome;
    private String nazionalita;
    private String proprietario;
    private double lung;
    private double larg;
    private boolean occupato;
    private static final double DEF_LARG = 4.0;
    private static final double DEF_LUNG = 10.0;

    public Barca(String nome, String nazionalita, String proprietario, double lung, double larg) {
        this.nome = nome;
        this.nazionalita = nazionalita;
        this.proprietario = proprietario;
        this.lung = (lung > 0) ? lung : DEF_LUNG;
        this.larg = (larg > 0) ? larg : DEF_LARG;
        this.occupato = false;
    }

    public String getNome() {
        return nome;
    }

    public String getNazionalita() {
        return nazionalita;
    }

    public String getProprietario() {
        return proprietario;
    }

    public void setProprietario(String proprietario) {
        this.proprietario = proprietario;
    }

    public double getLung() {
        return lung;
    }

    public double getLarg() {
        return larg;
    }

    public boolean isOccupato() {
        return occupato;
    }
   
    @Override
    public String toString() {
        return "Barca [nome=" + nome + ", nazionalita=" + nazionalita + ", proprietario=" + proprietario
                + ", lung=" + lung + ", larg=" + larg +
                 ", occupato=" + occupato + "]";
    }
}
