public abstract class Animale {
    private String nome;

    public Animale(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public abstract void verso(); // metodo vuoto

    public void miPresento() {
        System.out.print("Ciao, sono " + nome + " faccio ");
        verso();
    }
}
