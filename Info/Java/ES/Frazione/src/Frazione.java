public class Frazione {
    private char segno;
    private int den;
    private int num;
    private final static char DEF_SEGNO = '+';
    private final static int DEF_DEN = 10;
    private final static int DEF_NUM = 0;

    public Frazione(){
        this.segno = DEF_SEGNO;
        this.num = DEF_NUM;
        this.den = DEF_DEN;
    }
    public Frazione(char segno, int num){
        this.segno = segno;
        this.num = num;
        this.den = DEF_DEN;
    }
    public Frazione(char segno, int num, int den){
        this.segno = segno;
        this.num = num;
        if(den > 0)
            this.den = den;
        else
            this.den = DEF_DEN;
    }

    public void setSegno(char segno) { 
        this.segno = segno;
    }

    public void setNumeratore(int num) {
        this.num = num;
    }

    public void setDenominatore(int den) {
        if(den > 0)
            this.den = den;
        else
            this.den = DEF_DEN;
    }

    public char getSegno(){
        return segno;
    }

    public int getNumeratore() {
        return num;
    }

    public int getDenominatore() {
        return den;
    }
    public float getValore(){
        return (float)num/den;
    }
    public boolean equals(Frazione f) {
        boolean stessoValore = false;
        if(getValore() == this.getValore()){
            stessoValore = true;
        }
        return stessoValore;
    }
    public String toString(){
        return segno + num + "/" + den;
    }
}
