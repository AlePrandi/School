public class Persona {
    private String nome;
    private String cognome;
    private String codFisc;

    public Persona(String nome, String cognome, String codFisc) {
        this.nome = nome;
        this.cognome = cognome;
        this.codFisc = codFisc;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCodFisc(String codFisc) {
        this.codFisc = codFisc;
    }

    public String getCodFisc() {
        return codFisc;
    }

    @Override
    public String toString() {
        return "Nome: " + nome + "  cognome: " + cognome + "    codice_fiscale: " + codFisc;
    }
}
