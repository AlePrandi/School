import java.util.Vector;

public class Azienda {
    private String nome;
    private String indirizzo;
    private Vector<Lavoratore> vLav;

    public Azienda(String nome, String indirizzo, Vector<Lavoratore> vLav) {
        this.nome = nome;
        this.indirizzo = indirizzo;
        vLav = new Vector<Lavoratore>();
    }

    public void addLav(Lavoratore l) {
        if (l != null) {
            vLav.add(l);
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }

    @Override
    public String toString() {
        return "Azienda [nome: " + nome + ", indirizzo: " + indirizzo + ", Lavoratori:  " + vLav + "]";
    }
    
}
