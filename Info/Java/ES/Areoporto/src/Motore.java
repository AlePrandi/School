public class Motore extends Aereo implements Comparabile{
    private int Cavalli;
    private final static int MIN_Cavalli=1;
    public Motore(String sigla,int Cavalli) {
        super(sigla);
        if(Cavalli<=0){
            this.Cavalli=MIN_Cavalli;
        }else{
            this.Cavalli=Cavalli;
        }
    }

    public int getCavalli() {
        return Cavalli;
    }

    @Override
    public boolean Comp(Aereo a) {
        if(a==null || getClass() != a.getClass()){
            return false;
        }else{
            if(getCavalli()>((Motore) a).getCavalli()){
                return true;
            }else{
                return false;
            }
        }
    }

    public String toString(){
        String s=super.toString();
        return s + " Cavalli: " + Cavalli;
    }
}
