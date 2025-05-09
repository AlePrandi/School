public class Autonoleggio {
    private final int MAX_AUTO;
    private int num_auto;
    private Veicolo[] vAuto;
    private String indirizzo;
    private Responsabile responsabile;
    private String nome;
    private final static int DEF_AUTO = 2000;

    public Autonoleggio(String nome, String indirizzo, Responsabile responsabile, int max_auto) {
        if (max_auto < 1)
            MAX_AUTO = 1;
        else if (max_auto > DEF_AUTO) {
            MAX_AUTO = DEF_AUTO;
        } else {
            MAX_AUTO = max_auto;
        }
        num_auto = 0;
        this.nome = nome;
        this.indirizzo = indirizzo;
        this.responsabile = responsabile;
        vAuto = new Veicolo[MAX_AUTO];
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setResp(Responsabile resp) {
        this.responsabile = resp;
    }

    public Responsabile getResp() {
        return responsabile;
    }

    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public void add(Veicolo auto) {
        if (auto != null) {
            if (num_auto < MAX_AUTO) {
                vAuto[num_auto] = auto;
                num_auto++;
            }
        }
    }

    public void ricercaTarga(String targa) {
        for (Veicolo auto : vAuto) {
            if (auto != null) {
                if (auto.getTarga().equals(targa)) {
                    System.out.println("Auto con quella targa: \n" + auto.toString());
                }
            }
        }
    }

    public void elencoVeicoli() {
        System.out.println("Elenco veicoli: ");
        for (int k = 0; k < num_auto; k++) {
            System.out.println(vAuto[k].toString());
        }
    }

    public String toString() {
        String str = "";
        for (int k = 0; k < num_auto; k++) {
            str += vAuto[k].toString() + "\n";
        }
        return str;
    }
}
