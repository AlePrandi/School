public class Giocatore {
    private String nome;
    private int eta;
    private double punteggio;
    private Ruolo ruolo;

    public Giocatore(String nome, int eta, Ruolo ruolo) {
        this.nome = nome;
        if(eta > 0)
            this.eta = eta;
        this.ruolo = ruolo;
    }

    public Giocatore(String nome, int eta, double punteggio, Ruolo ruolo) {
        this.nome = nome;
        if(eta > 0)
            this.eta = eta;
        this.punteggio = punteggio;
        this.ruolo = ruolo;
    }

    public String getNome() {
        return nome;
    }

    public double getPunteggio() {
        return punteggio;
    }

    public void setPunteggio(double nuovoPunteggio) {
        punteggio = nuovoPunteggio;
    }

    public int getEta() {
        return eta;
    }

    public void setEta(int nuovaEta) {
        eta = nuovaEta;
    }

    public Ruolo getRuolo(){
        return ruolo;
    }

    public void setRuolo(Ruolo ruolo) {
        this.ruolo = ruolo;
    }
    public String toString() {
        return "Nome: " + nome + " Eta: " + eta + " Punteggio: " + punteggio;
    }
}
