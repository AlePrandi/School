public class Dado{

    private int num_uscito;
    private final int N_FACCE;
    private static final int FACCE_DEFAULT = 6;

    public Dado(int n_facce) {
        if (n_facce < FACCE_DEFAULT)
            N_FACCE = n_facce;
        else
            N_FACCE = FACCE_DEFAULT;
        num_uscito = lanciaDado();
    }

    public Dado() {
        N_FACCE = FACCE_DEFAULT;
        num_uscito = lanciaDado();
    }

    public int lanciaDado() {
        int numero = (int) Math.floor(Math.random() * N_FACCE + 1);
        return numero;
    }

    public int getLancio() {
        return num_uscito;
    }
}