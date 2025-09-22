import java.io.IOException;

public class ValoreNonValido extends IOException{ 
    public ValoreNonValido(String s){
        super(s);
    }

    public ValoreNonValido(){
        super("Valore non valido");
    }
}
