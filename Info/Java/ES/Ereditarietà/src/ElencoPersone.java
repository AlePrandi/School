public class ElencoPersone {
    private Persona[] elenco;
    private int cont;
    private final int MAX_PERSONE;
    private static final int DEF_PERSONE = 10;

    public ElencoPersone(int max_persone) {
        MAX_PERSONE = (max_persone > 0) ? max_persone : DEF_PERSONE;
        elenco = new Persona[MAX_PERSONE];
    }

    public void add(Persona p) {
        if (p != null && cont < MAX_PERSONE) {
            elenco[cont] = p;
            cont++;
        }
    }

    public String toString() {
        String str = "";
        for (int i = 0; i < cont; i++) {
            str += elenco[i].toString() + '\n';
        }
        return str;
    }
}
