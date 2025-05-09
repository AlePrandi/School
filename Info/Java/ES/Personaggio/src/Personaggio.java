public class Personaggio {
    private String nome;
    private Cappello cappello;
    private Maglia maglia;
    private Pantalone pantalone;
    private int nArti;
    private int nGambe;
    private Arto[] arti;
    private Gambe[] gambe;

    private static final int MAX_ARTI = 4;
    private static final int MAX_GAMBE = 2;

    public Personaggio(String nome, Cappello cappello, Maglia maglia, Pantalone pantalone) {
        this.nome = nome;
        this.cappello = cappello;
        this.maglia = maglia;
        this.pantalone = pantalone;
        this.nArti = 0;
        this.nGambe = 0;
        this.arti = new Arto[MAX_ARTI];
        this.gambe = new Gambe[MAX_GAMBE];
    }

    public void addArto(Arto a) {
        if (a != null && nArti <= MAX_ARTI) {
            arti[nArti] = a;
            nArti++;
        }
    }

    public void addGambe(Gambe g) {
        if (g != null && nGambe <= MAX_GAMBE) {
            gambe[nGambe] = g;
            nGambe++;
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Cappello getCappello() {
        return cappello;
    }

    public void setCappello(Cappello cappello) {
        this.cappello = cappello;
    }

    public Maglia getMaglia() {
        return maglia;
    }

    public void setMaglia(Maglia maglia) {
        this.maglia = maglia;
    }

    public Pantalone getPantalone() {
        return pantalone;
    }

    public void setPantalone(Pantalone pantalone) {
        this.pantalone = pantalone;
    }

    @Override
    public String toString() {
        return "Personaggio [nome = " + nome + ", cappello = " + cappello + ", maglia = " + maglia + ", pantalone = "
                + pantalone + ", nArti = " + nArti + ", nGambe = " + nGambe + "]";
    }

    public class Arto {
        private double forza;
        private Arma arma;

        public Arto(double forza, Arma arma) {
            this.forza = (forza > 0.0) ? forza : 1;
            this.arma = arma;
        }

        public double getForza() {
            return forza;
        }

        public void setForza(double forza) {
            this.forza = forza;
        }

        public Arma getArma() {
            return arma;
        }

        public void setArma(Arma arma) {
            this.arma = arma;
        }

        @Override
        public String toString() {
            return "Arto [forza = " + forza + ", arma = " + arma + "]";
        }
    }

    public class Gambe {
        private double forza;

        public Gambe(double forza) {
            this.forza = forza;
        }

        public double getForza() {
            return forza;
        }

        public void setForza(double forza) {
            this.forza = forza;
        }

        @Override
        public String toString() {
            return "Gambe [forza = " + forza + "]";
        }
    }
}
