public class Maglia {
    private String nome;
    private String colore;
    
    public Maglia(String nome, String colore) {
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
        return "Maglia [nome=" + nome + ", colore=" + colore + "]";
    }
}
