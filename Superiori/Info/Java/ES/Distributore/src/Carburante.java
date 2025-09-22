class Carburante {
    private float prezzo;
    private String tipo;
    
    //private TipoCarburante tipoC;
    private static final String[] POS_TIPI = {"benzina", "diesel", "gpl", "metano"};
    private static final String DEF_TIPO = "benzina"; // 
    private static final float DEF_PREZZO = 1.5f;

    public Carburante() {
        tipo = DEF_TIPO;
        prezzo = DEF_PREZZO;
    }

    private int isTipo(String tipo){
        int tro = -1;
        int k = 0;
        while(k < POS_TIPI.length && tro == -1) {
            if(tipo.equals(POS_TIPI[k])) 
                tro = k;
            k++;
        }
        return tro;
    }

    public Carburante(String tipo, float prezzo) {
        if(isTipo(tipo) != -1) {
            this.tipo = tipo;
        }else{
            this.tipo = DEF_TIPO;
        }
        if (prezzo > 0) {
            this.prezzo = prezzo;
        }else{
            this.prezzo = DEF_PREZZO;
        }
    }

    public void setTipo(String tipo) {
        if(tipo != null && isTipo(tipo) != -1) { // prima che tipo esista e poi che sia valido
            this.tipo = tipo;
        }
        // non c'è l'else perchè sono sicuro che sia v
    }

    public String getTipo() {
        return tipo;
    }

    public void setPrezzo(float prezzo) {
        if (prezzo > 0) {
            this.prezzo = prezzo;
        } else {
            this.prezzo = DEF_PREZZO;
        }
    }

    public float getPrezzo() {
        return prezzo;
    }

    public boolean equals(Carburante c) {
        return this.prezzo == c.getPrezzo();
    }

    public String toString() {
        return "Carburante [tipo= " + tipo + ", prezzo= " + prezzo + "]";
    }
}