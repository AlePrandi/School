public class LavoratoriConStraordinariPagati extends Lavoratore{
    private int oreStraord;
    private static float RETR_ORARIA = 10.0f;
    private final static int DEF_ORE_STR = 10;

    public LavoratoriConStraordinariPagati(String nome, int livello, int oreStraord) {
        super(nome, livello);
        if(oreStraord > 0)
            this.oreStraord = oreStraord;
        else
            this.oreStraord = DEF_ORE_STR;
    }

    public int getOreStraordinari() {
        return oreStraord;
    }

    public void setOreStraordinari(int oreStraord) {
        if(oreStraord > 0)
            this.oreStraord = oreStraord;
        else
            this.oreStraord = DEF_ORE_STR;
    }
    public static void setRetribuzioneOraria(float retribuzioneOraria){
        if(retribuzioneOraria > 0)
            RETR_ORARIA = retribuzioneOraria;
    }
    public float getStipendio(){
        return super.getStipendio() + (oreStraord * RETR_ORARIA);
    }

    public String toString() {
        return super.toString() + " Ore straordinario: " + oreStraord + " Stipendio Finale: "
                + getStipendio();
    }
}
