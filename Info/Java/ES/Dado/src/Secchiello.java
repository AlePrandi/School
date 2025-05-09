public class Secchiello {
    private final int NUM_MAX;
    private int num_dadi;
    private Dado[] vDadi;

    public Secchiello(int max_dadi) {
        if (max_dadi < 1)
            NUM_MAX = 1;
        else
            NUM_MAX = max_dadi;
        num_dadi = 0;
        vDadi = new Dado[NUM_MAX];
    }

    public void add(Dado dado) {
        if (dado != null) {
            if (num_dadi < NUM_MAX) {
                vDadi[num_dadi] = dado;
                num_dadi++;
            }
        }
    }

    public void lancio() {
        for (int k = 0; k < num_dadi; k++) {
            vDadi[k].lanciaDado();
        }
    }

    public int getSomma() {
        int somma = 0;
        for (int k = 0; k < num_dadi; k++) {
            somma = somma + vDadi[k].getLancio();
        }
        return somma;
    }

    public String toString() {
        for (int k = 0; k < num_dadi; k++) {
            vDadi[k].toString();
            System.out.println("\n");
        }
        return " somma totale: " + getSomma();
    }
}
