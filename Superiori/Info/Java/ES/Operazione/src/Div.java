public class Div implements Operazione {

    public Div(){

    }
    
    public double getRisultato(double x, double y){
        if(y != 0){
            return x / y;
        }
        return 0;
    }
}
