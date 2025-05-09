public class Utente {
    private String nome;
    private String cognome;
    private String cod_fisc;

    public Utente(String nome, String cognome, String cod_fisc) {
        this.nome = nome;
        this.cognome = cognome;
        this.cod_fisc = cod_fisc;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public String getCod_fisc() {
        return cod_fisc;
    }

    @Override
    public String toString() {
        return "Utente [nome=" + nome + ", cognome=" + cognome + ", cod_fisc=" + cod_fisc + "]";
    }
}
