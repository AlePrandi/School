public class Lavoratore {
    private String nome;
    private int livello;
    private float stipendio;
    private static final int DEF_LIV = 0;
    private static final float DEF_STIP = 1000;
    private static final int MAX_LIV = 5;
    private static final int MIN_LIV = 0; 

    public Lavoratore(String nome, int livello) {
        this.nome = nome;
        if(livello >= MIN_LIV && livello <= MAX_LIV)
            this.livello = livello;
        else
            this.livello = DEF_LIV;
        this.stipendio = DEF_STIP;
    }

    public String getNome() {
        return nome;
    }

    public int getLivello() {
        return livello;
    }

    public float getStipendio() {
        return stipendio;
    }

    public void setLivello(int livello) {
        if(livello >= MIN_LIV && livello <= MAX_LIV)
            this.livello = livello;
        else
            this.livello = DEF_LIV;
    }

    public void setStipendio(float stipendio) {
        if(stipendio > 0)
            this.stipendio = stipendio;
        else
            this.stipendio = DEF_STIP;
    }
    public String toString(){
        return "Lavoratore: " + nome + " Livello: " + livello + " Stipendio Base: " + stipendio;
    }
}
