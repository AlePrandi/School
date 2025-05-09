import java.util.Vector;
public class VideotecaVector {
    private String nome;
    private String indirizzo;
    private Vector <Cassetta> cassette;

    public VideotecaVector(String nome, String indirizzo){
        this.nome = nome;
        this.indirizzo = indirizzo;
        cassette = new Vector<Cassetta>();
    }

    public String getNome() {
        return nome;
    }

    public void add(Cassetta c) {
        if (c != null){
            cassette.add(c);
        }
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

    public double getValNegozio() {
        double tot = 0;
        for (int k = 0; k < cassette.size(); k++) {
            if(cassette.elementAt(k) instanceof Dvd)
                tot += Dvd.getPrezzo() * cassette.elementAt(k).getN_copie();
            if(cassette.elementAt(k) instanceof Cd)
                tot += Cd.getPrezzo() * cassette.elementAt(k).getN_copie();
        }
        return tot;
    }

    public void compro(int cod){
        int k=0;
        boolean tro=false;
        while(k<cassette.size() && tro==false){
            if(cassette.elementAt(k).getCodice() == cod){
                cassette.elementAt(k).setN_copie(cassette.elementAt(k).getN_copie() + 1);
                tro=true;
            }
            k++;
        }
    }

    public void vendo(int cod){
        int k=0;
        boolean tro=false;
        while(k<cassette.size() && tro==false){
            if(cassette.elementAt(k).getCodice() == cod){
                cassette.elementAt(k).setN_copie(cassette.elementAt(k).getN_copie() - 1);
                tro=true;
            }
            k++;
        }
    }

    @Override
    public String toString() {
        return "Videoteca [nome=" + nome + ", indirizzo=" + indirizzo + ", cassette=" + cassette + "]";
    }

}

