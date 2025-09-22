public class Alianti extends Aereo implements Comparabile{
    private int areodinamica;
    private final static int MIN_AREODINAMICA=1;
    public Alianti(String sigla, int areodinamica) {
        super(sigla);
        this.areodinamica = (areodinamica > 0) ? areodinamica : MIN_AREODINAMICA;
    }

    public int getAreodinamica() {
        return areodinamica;
    }
    public String toString(){
        String s=super.toString();
        return s + " Areodinamica: " + areodinamica;
    }

    @Override
    public boolean Comp(Aereo a) {
        if(a==null || getClass() != a.getClass()){
            return false;
        }else{
            if(getAreodinamica()>((Alianti) a).getAreodinamica()){
                return true;
            }else{
                return false;
            }
        }
    }
}
