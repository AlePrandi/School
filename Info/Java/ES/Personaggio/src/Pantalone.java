public class Pantalone {
    private String nome;
    private String colore;
    
    public Pantalone(String nome, String colore) {
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
        return "Pantalone [nome=" + nome + ", colore=" + colore + "]";
    }
}
