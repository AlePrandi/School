public class Rubrica {
    private final int MAX_NUMERI;
    private int num_contatti;
    private Contatto[] vCont;
    private static final int DEF_CONTATTI = 200;

    public Rubrica(int max_contatti) {
        MAX_NUMERI = (max_contatti < 0) ? DEF_CONTATTI : max_contatti;
        num_contatti = 0;
        vCont = new Contatto[MAX_NUMERI];
    }

    public void add(Contatto c) {
        if (c != null) {
            if (num_contatti < MAX_NUMERI) {
                vCont[num_contatti] = c;
                num_contatti++;
            }
        }
    }

    public void cercaContattoNome(String nome, String numero) {
        if (nome != null) {
            for (int k = 0; k < num_contatti; k++) {
                if(vCont[k].getNome().equals(nome)){
                    vCont[k].setNumero(numero);
                }
            }
        }
    }

    public void elencoContatti() {
        for (int k = 0; k < num_contatti; k++) {
            System.out.println(vCont[k].toString());
        }
    }

    public String toString() {
        String str = "";
        for (int k = 0; k < num_contatti; k++) {
            str += vCont[k].toString() + "\n";
        }
        return str;
    }
}
