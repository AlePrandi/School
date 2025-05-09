import java.util.Vector;

public class LibreriaVector {
    private String nome;
    private String citta;
    private Vector<Libro> vLibri;

    public LibreriaVector(String nome, String citta) {
        this.nome = nome;
        this.citta = citta;
        vLibri = new Vector<Libro>();
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

    public void addEl(Libro l) {
        if (l != null) {
            vLibri.add(l);
        }
    }

    public int getNlibri() {
        return vLibri.size();
    }

    private int cercaGenere(Generi g){
        int tro = -1, k = 0;
        while (tro == -1 && k < Generi.values().length){
            if(g == Generi.values()[k]){
                tro = k;
            }
            k++;
        }
        return tro;
    }

    public void CambiaPrezzo(String titolo, int perc, char op) {
        int k = 0, tro = -1;
        while (k < vLibri.size() && tro == -1) {
            if (vLibri.get(k).getTitolo().equals(titolo)) {
                if (op == 'a')
                    vLibri.get(k).setPrezzo(vLibri.get(k).getPrezzo() + (vLibri.get(k).getPrezzo() * perc / 100));
                else {
                    if (op == 's')
                        vLibri.get(k).setPrezzo(vLibri.get(k).getPrezzo() - (vLibri.get(k).getPrezzo() * perc / 100));
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
        for (Libro l : vLibri) {
            if (l.getGenere() == Generi.HORROR) {
                if (contH == 0) {
                    min_Horror = l.getPrezzo();
                    contH++;
                } else {
                    if (l.getPrezzo() < min_Horror) {
                        min_Horror = l.getPrezzo();
                        contH++;
                    }
                }
            }
            if (l.getGenere() == Generi.GIALLO) {
                if (contG == 0) {
                    min_Giallo = l.getPrezzo();
                    contG++;
                } else {
                    if (l.getPrezzo() < min_Giallo) {
                        min_Giallo = l.getPrezzo();
                        contG++;
                    }
                }
            }
            if (l.getGenere() == Generi.ROMANZO) {
                if (contR == 0) {
                    min_Romanzo = l.getPrezzo();
                    contR++;
                } else {
                    if (l.getPrezzo() < min_Romanzo) {
                        min_Romanzo = l.getPrezzo();
                        contR++;
                    }
                }
            }
        }
        System.out.println("Il minimo dei libri gialli e: " + min_Giallo);
        System.out.println("Il minimo dei libri horror e: " + min_Horror);
        System.out.println("Il minimo dei romanzi e: " + min_Romanzo);
    }

    public void Statistica2() {
        float[] vMin = new float[Generi.values().length];
        int[] vCont = new int[Generi.values().length];
        int posGenere;
        for (Libro l: vLibri) {
            posGenere = cercaGenere(l.getGenere());
            if (vCont[posGenere] == 0) {
                vMin[posGenere] = l.getPrezzo();

            } else {
                if (l.getPrezzo() < vMin[posGenere]) {
                    vMin[posGenere] = l.getPrezzo();
                }
            }
            vCont[posGenere]++;
        }
        for (int k = 0; k < Generi.values().length; k++) {
            System.out.println(Generi.values()[k] + ": " + vMin[k]);
        }
    }

    @Override
    public String toString() {
        String str = "";
        float prezzoTotale = 0;
        float prezzoMedio;
        for (Libro l : vLibri) {
            str += l.toString() + "\n";
            prezzoTotale += l.getPrezzo();
        }
        if (vLibri.size() == 0)
            prezzoMedio = 0;
        else
            prezzoMedio = prezzoTotale / vLibri.size();
        return "Nome: " + nome + " Citta: " + citta + "\n" + str + "\nPrezzo medio: " + prezzoMedio;
    }
}
