public class Distributore {
    private String nome;
    private String indirizzo;
    private Carburante[] vCarb;
    private int numPompe;
    private final int MAX_CARBURANTI;

    public Distributore(String nome, String indirizzo, int max_pompe) {
        if (max_pompe < 4) { // < 4 in modo che ci sia almeno una pompa per tipo di carburante
            MAX_CARBURANTI = 4;
        } else {
            MAX_CARBURANTI = max_pompe;
        }
        this.nome = nome;
        this.indirizzo = indirizzo;
        vCarb = new Carburante[MAX_CARBURANTI];
        numPompe = 0;
    }

    public void add(Carburante carburante) {
        if (numPompe < MAX_CARBURANTI) {
            vCarb[numPompe] = carburante;
            numPompe++;
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

    public void aumenta(String tipo, float percentuale) {
        for (int i = 0; i < numPompe; i++) {
            if (vCarb[i].getTipo().equalsIgnoreCase(tipo)) {
                float prezzoAttuale = vCarb[i].getPrezzo();
                float aumento = prezzoAttuale * (percentuale / 100);
                vCarb[i].setPrezzo(prezzoAttuale + aumento);
            }
        }
    }

    public String getStatistiche() {
        float prezzoMin = 0;
        float prezzoMax = 0;
        float prezzoMedio = 0;
        if (numPompe > 0) {
            prezzoMin = vCarb[0].getPrezzo();
            prezzoMax = vCarb[0].getPrezzo();
            prezzoMedio = 0;

            for (int i = 0; i < numPompe; i++) {
                float prezzo = vCarb[i].getPrezzo();
                if (prezzo < prezzoMin) {
                    prezzoMin = prezzo;
                }
                if (prezzo > prezzoMax) {
                    prezzoMax = prezzo;
                }
                prezzoMedio += prezzo;
            }

            prezzoMedio /= numPompe;
        } 
       return "Prezzo minimo: " + prezzoMin + "\nPrezzo massimo: " + prezzoMax + "\nPrezzo media: " + prezzoMedio;
    }

    public String toString() {
        return "Distributore [nome= " + nome + ", indirizzo= " + indirizzo + getStatistiche();
    }
}
