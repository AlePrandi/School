public class Cappello {
    private String nome;
    private String colore;
    
    public Cappello(String nome, String colore) {
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
        return "Cappello [nome=" + nome + ", colore=" + colore + "]";
    }
}
