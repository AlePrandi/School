public class Libreria {
    private String nome;
    private String citta;
    private Libro[] vLibri;
    private int n_libri;
    private final int MAX_LIBRI;
    private static final int DEF_LIBRI = 1000;

    public Libreria(String nome, String citta, int max_libri) {
        this.nome = nome;
        this.citta = citta;
        this.n_libri = 0;
        MAX_LIBRI = (max_libri > 0) ? max_libri : DEF_LIBRI;
        vLibri = new Libro[MAX_LIBRI];
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCitta() {
        return citta;
    }

    public void setCitta(String citta) {
        this.citta = citta;
    }

    public void add(Libro l) {
        if (l != null && n_libri < MAX_LIBRI) {
            vLibri[n_libri] = l;
            n_libri++;
        }
    }

    public void CambiaPrezzo(String titolo, int perc, char op) {
        int k = 0, tro = -1;
        while (k < n_libri && tro == -1) {
            if (vLibri[k].getTitolo().equals(titolo)) {
                if (op == 'a')
                    vLibri[k].setPrezzo(vLibri[k].getPrezzo() + (vLibri[k].getPrezzo() * perc / 100));
                else {
                    if (op == 's')
                        vLibri[k].setPrezzo(vLibri[k].getPrezzo() - (vLibri[k].getPrezzo() * perc / 100));
                }
            }
            k++;
        }
    }

    public void Statistica() {
        float min_Horror = 0;
        float min_Giallo = 0;
        float min_Romanzo = 0;
        float contH = 0;
        float contG = 0;
        float contR = 0;
        for (int k = 0; k < n_libri; k++) {
            if (vLibri[k].getGenere() == Generi.HORROR) {
                if (contH == 0) {
                    min_Horror = vLibri[k].getPrezzo();
                    contH++;
                } else {
                    if (vLibri[k].getPrezzo() < min_Horror) {
                        min_Horror = vLibri[k].getPrezzo();
                        contH++;
                    }
                }
            }
            if (vLibri[k].getGenere() == Generi.GIALLO) {
                if (contG == 0) {
                    min_Giallo = vLibri[k].getPrezzo();
                    contG++;
                } else {
                    if (vLibri[k].getPrezzo() < min_Giallo) {
                        min_Giallo = vLibri[k].getPrezzo();
                        contG++;
                    }
                }
            }
            if (vLibri[k].getGenere() == Generi.ROMANZO) {
                if (contR == 0) {
                    min_Romanzo = vLibri[k].getPrezzo();
                    contR++;
                } else {
                    if (vLibri[k].getPrezzo() < min_Romanzo) {
                        min_Romanzo = vLibri[k].getPrezzo();
                        contR++;
                    }
                }
            }
        }
        System.out.println("Il minimo dei libri gialli e: " + min_Giallo);
        System.out.println("Il minimo dei libri horror e: " + min_Horror);
        System.out.println("Il minimo dei romanzi e: " + min_Romanzo);
    }

    @Override
    public String toString() {
        String str = "";
        float prezzoTotale = 0;
        float prezzoMedio;
        for (int k = 0; k < n_libri; k++) {
            str += vLibri[k].toString() + "\n";
            prezzoTotale += vLibri[k].getPrezzo();
        }
        if (n_libri == 0)
            prezzoMedio = 0;
        else
            prezzoMedio = prezzoTotale / n_libri;
        return "Nome: " + nome + " Citta: " + citta + "\n" + str + "\n Prezzo medio: " + prezzoMedio;
    }
}
