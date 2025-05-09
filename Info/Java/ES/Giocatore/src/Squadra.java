public class Squadra {

    private String nome;
    private Giocatore[] vGioc;
    //private Ruolo[] ruoli;
    private int numGiocatori;
    private final int N_MAX_GIOCATORI;
    private static final int DEF_GIOCATORI = 10;

    public Squadra(String nome, int giocatori) {
        this.nome = nome;
        if (giocatori < 1) 
            N_MAX_GIOCATORI = DEF_GIOCATORI;
        else
            N_MAX_GIOCATORI = giocatori;
        vGioc = new Giocatore[N_MAX_GIOCATORI];
        numGiocatori = 0;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return nome;
    }

    public void add(Giocatore gioc) {
       if (numGiocatori < N_MAX_GIOCATORI) {
            vGioc[numGiocatori] = gioc;
            numGiocatori++;
       }
    }

    public void setPunteggio(String nome, double valore) {
        for (int i = 0; i < numGiocatori; i++) {
            if (vGioc[i].getNome().equals(nome)) {
                vGioc[i].setPunteggio(valore);
            }
        }
    }

    public double getPunteggioMedio() {
        double totalePunteggio = 0;
        int cont = 0;

        for (int i = 0; i < numGiocatori; i++) {
            totalePunteggio += vGioc[i].getPunteggio();
            cont++;
        }

        return totalePunteggio / cont;
    }

    public void passatoAnno() {
        for (int i = 0; i < numGiocatori; i++) {
            vGioc[i].setEta((vGioc[i].getEta()) + 1);
        }
    }

    public String toString() {
        for (int k = 0; k < numGiocatori; k++) {
            System.out.println(vGioc[k].toString());
        }
        return "punteggio medio della squadra: " + getPunteggioMedio();
    }
}
