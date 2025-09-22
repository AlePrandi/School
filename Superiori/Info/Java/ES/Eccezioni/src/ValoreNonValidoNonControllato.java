public class ValoreNonValidoNonControllato extends RuntimeException{ 
    public ValoreNonValidoNonControllato(String s){
        super(s);
    }

    public ValoreNonValidoNonControllato(){
        super("Valore non valido");
    }
}
