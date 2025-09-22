public class Mostro {
    private String nome; // -privato +pubblico in violet
    private int vita;
    private int forza;

    private static final int MIN_VITA = 0; // final = costante static = uguale per tuttiù
    private static final int MAX_VITA = 300;
    private static final int MIN_FORZA = 5;
    private static final int MAX_FORZA = 10;
    private static final int MIN_DADO = 1;
    //private static final int MAX_DADO = 6;

    private final int FACCE;
    private final static int DEFAULT_FACCE = 6;

    public Mostro(String nome, int forza, int vita, int facce) {
        this.nome = nome;
        FACCE = (facce >= DEFAULT_FACCE) ? facce : DEFAULT_FACCE;
        if (forza >= MIN_FORZA && forza <= MAX_FORZA)
            this.forza = forza;
        else
            this.forza = MIN_FORZA;
        if (vita >= MIN_VITA && vita <= MAX_VITA)
            this.vita = vita;
        else
            this.vita = MAX_VITA / 2;
    }

    public Mostro(String nome, int facce) {
        this.nome = nome;
        this.vita = (int) (Math.random() * (MAX_VITA - MIN_VITA + 1)) + MIN_VITA;// L'ULTIMO E LA PARTENZA
        this.forza = (int) (Math.random() * (MAX_FORZA - MIN_FORZA + 1)) + MIN_FORZA;
        FACCE = (facce >= DEFAULT_FACCE) ? facce : DEFAULT_FACCE;
    }

    public String toString() {
        return nome + ": vita = " + vita + ", forza = " + forza + ", dado da = " + FACCE;
    }

    public String getNome() {
        return nome;
    }

    public int getVita() {
        return vita;
    }

    public int getForza() {
        return forza;
    }

    public void setVita(int vita) {
        if (vita >= MIN_VITA && vita <= MAX_VITA)
            this.vita = vita;
        else if (vita < MIN_VITA)
            this.vita = MIN_VITA;
        else if (vita > MAX_VITA)
            this.vita = MAX_VITA;
    }

    public void setForza(int forza) {
        if (forza >= MIN_FORZA && forza <= MAX_FORZA)
            this.forza = forza;
        else
            this.forza = MIN_FORZA;
    }

    private int getLancio() {
        return (int) (Math.random() * FACCE) + MIN_DADO;
    }

    public void attDa(Mostro m) {
        int dado = getLancio();

        setVita(vita - (dado * m.getForza()));
    }

    public void gioca(Mostro m) {
        while (vita > 0 && m.getVita() > 0) {
            attDa(m);
            //System.out.println(this);
            if (this.vita > 0) {
                m.attDa(this);
                //System.out.println(m);
            }
        }
        System.out.print("Ha vinto ");
        if (vita == 0) {
            System.out.println(m.getNome());
        }else{
            System.out.println(nome);
        }
    }
}
