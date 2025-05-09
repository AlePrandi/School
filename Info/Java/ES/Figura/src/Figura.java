public class Figura {
    private String nome;
    private int n_punti;
    private Punto[] vpunti;
    private final int MAX_PUNTI;

    public Figura(String nome, int max_punti) {
        this.nome = nome;
        if (max_punti < 3) {
            MAX_PUNTI = 3;
        } else
            MAX_PUNTI = max_punti;
        vpunti = new Punto[MAX_PUNTI];
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return nome;
    }

    public void add(Punto punto) {
        if (punto != null) {
            if (n_punti < MAX_PUNTI) {
                vpunti[n_punti] = punto;
                n_punti++;
            }
        }
    }

    public float calcolaPerimetro() {
        float perimetro = 0;
        if (n_punti == MAX_PUNTI) {
            for (int i = 0; i < n_punti - 1; i++) {
                perimetro += vpunti[i].getDistanza(vpunti[i + 1]);
            }
        }
        perimetro += vpunti[0].getDistanza(vpunti[n_punti - 1]);
        return perimetro;
    }

    public String toString() {
        for (int i = 0; i < n_punti; i++) {
            System.out.println(vpunti[i].toString());
        }
        return "Coordinate vertici";
    }
}
