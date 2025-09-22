import java.util.Vector;

public class Palazzo {
    private String nome;
    private String indirizzo;
    private String numCivico;
    private Vector<Piano> vPiani;

    public Palazzo(String nome, String indirizzo, String numCivico, Piano p) {
        this.nome = nome;
        this.indirizzo = indirizzo;
        this.numCivico = numCivico;
    }

    public String getNome() {
        return nome;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public String getNumCivico() {
        return numCivico;
    }

    public void addPiano(Piano p) {
        if (p != null) {
            vPiani.add(p);
        }
    }

    public class Piano {
        private int numero;
        private double valMetro;
        private Vector<Appartamento> vApp;

        public Piano(int numero, double valMetro) {
            this.numero = numero;
            this.valMetro = valMetro;
        }

        public int getNumero() {
            return numero;
        }

        public double getValMetro() {
            return valMetro;
        }

        public void addAppartamento(Appartamento a) {
            if (a != null) {
                vApp.add(a);
            }
        }

        @Override
        public String toString() {
            return "Piano [numero=" + numero + ", valMetro=" + valMetro + ", vApp=" + vApp + "]";
        }

        public class Appartamento {

            private int numero;
            private double metri2;
            private Vector<Stanza> vStanze;

            public Appartamento(int numero, double larghezza, double lunghezza) {
                this.numero = numero;
                this.metri2 = larghezza * lunghezza;
            }

            public int getNumero() {
                return numero;
            }

            public double getMetri2() {
                return metri2;
            }

            public int getNstanze() {
                return vStanze.size();
            }

            public double getValore() {
                return valMetro * metri2;
            }

            public void addStanza(double larg, double lung) {
                if (larg > 3 && lung > 3) { // dimensioni minime per una stanza
                    Stanza s = new Stanza(larg, lung);
                    vStanze.add(s);
                } else {
                    // throw new dimensioneTroppoPiccola
                }
            }

            @Override
            public String toString() {
                return "Appartamento [numero=" + numero + ", metri2=" + metri2 + ", vStanze=" + vStanze + "]";
            }

            public class Stanza {
                private double larg;
                private double lung;

                public Stanza(double larg, double lung) {
                    this.larg = (larg > 3) ? larg : 3;
                    this.lung = (lung > 3) ? lung : 3;
                }

                public double getLarg() {
                    return larg;
                }

                public double getLung() {
                    return lung;
                }

                @Override
                public String toString() {
                    return "Stanza [larg=" + larg + ", lung=" + lung + "]";
                }
            }
        }
    }
}
