public class Responsabile {
    private String nome;
    private String cognome;
    private String telefono;
    private int anniSer;
    
    public Responsabile(String nome, String cognome, String telefono, int anniSer) {
        this.nome = nome;
        this.cognome = cognome;
        this.telefono = telefono;
        this.anniSer = anniSer;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public String getTelefono() {
        return telefono;
    }

    public int getAnniSer() {
        return anniSer;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    @Override
    public String toString() {
        return "Responsabile [nome=" + nome + ", cognome=" + cognome + ", telefono=" + telefono + ", anniSer=" + anniSer
                + "]";
    }
}
