public class Vestito {
    private String nome;
    private String colore;
    
    public Vestito(String nome, String colore) {
        this.nome = nome;
        this.colore = colore;
    }

    public String getNome() {
        return nome;
    }

    public String getColore() {
        return colore;
    }

    @Override
    public String toString() {
        return "Vestito [nome=" + nome + ", colore=" + colore + "]";
    }
}
