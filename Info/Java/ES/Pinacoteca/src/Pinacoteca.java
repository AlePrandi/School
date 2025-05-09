public class Pinacoteca {
    private String nome;
    private int n_quadri;
    private Quadro[] vQuadri;
    private final int MAX_QUADRI;
    private static final int DEF_QUADRI = 100;

    public Pinacoteca(String nome, int max_quadri) {
        MAX_QUADRI = (max_quadri > 0) ? max_quadri : DEF_QUADRI;
        this.nome = nome;
        n_quadri = 0;
        vQuadri = new Quadro[MAX_QUADRI];
    }

    public void addQuadro(Quadro q) {
        if (q != null && n_quadri < MAX_QUADRI) {
            vQuadri[n_quadri] = q;
            n_quadri++;
        }
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setPrezzo(String titolo, int perc) {
        int k = 0, tro = -1;
        while (k < n_quadri && tro == -1) {
            if (vQuadri[k] != null && vQuadri[k].getTitolo().equals(titolo)) {
                vQuadri[k].setValore(vQuadri[k].getValore() + (vQuadri[k].getValore() * perc / 100));
                tro = k;
            } else
                k++;
        }
    }

    public double getValoreMedio() {
        double medio = 0;
        for (Quadro q : vQuadri) {
            medio += q.getValore();
        }
        return medio / n_quadri;
    }

    public String toString() {
        String str = "";
        for (int k = 0; k < n_quadri; k++) {
            str += vQuadri[k].toString() + "\n";
        }
        return str;
    }
}
