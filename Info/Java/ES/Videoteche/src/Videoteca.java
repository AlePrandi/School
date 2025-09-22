public class Videoteca {
    private String nome;
    private String indirizzo;
    private Cassetta[] Cassette;
    private int n_cassette;

    private double conto;

    private int cont;

    public Videoteca(String nome, String indirizzo, int n_cassette) {
        this.nome = nome;
        this.indirizzo = indirizzo;
        this.n_cassette = n_cassette;
        Cassette = new Cassetta[n_cassette];
        cont = 0;
        conto = 0;
    }

    public String getNome() {
        return nome;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public void Add(Cassetta c){
        if(cont<n_cassette && c!=null){
            Cassette[cont]=c;
            cont++;
        }
    }

    public void Vendo(int codice){
        int k=0;
        boolean tro=false;
        while(k<cont && !tro){
            if(Cassette[k].getCodice()==codice){
                if(Cassette[k] instanceof Dvd){
                    conto=conto + ((Dvd) Cassette[k]).getPrezzoScontato();
                } else if (Cassette[k] instanceof Cd) {
                    conto=conto+((Cd) Cassette[k]).getPrezzoScontato();
                }
                tro=true;
            }
                k++;

        }
    }

    public void Compro(int codice){
        int k=0;
        boolean tro=false;
        while(k<cont && tro==false){
            if(Cassette[k].getCodice()==codice){
                if(Cassette[k] instanceof Dvd){
                    conto=conto-((Dvd) Cassette[k]).getPrezzoScontato();
                } else if (Cassette[k] instanceof Cd) {
                    conto=conto-((Cd) Cassette[k]).getPrezzoScontato();
                }
                tro=true;
            }
            k++;
        }
    }

    private double GetValoreNegozio(){
        return conto;
    }

    public String toString(){
        String s="";
        for(int k=0;k<cont;k++){
            s = s + Cassette[k].toString();
        }
        return "Nome: " + nome + " Indirizzo: " + indirizzo +
         " Saldo: " + conto + "\n" +  s + " Valore del Negozio: " + GetValoreNegozio();
    }

}
