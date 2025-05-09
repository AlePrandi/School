public class PostoAuto {
    private int numero;
    private Auto occupatoDa;

    public PostoAuto(int numero) {
        this.numero = numero;
    }
    public boolean isOccupato(){
        return occupatoDa != null;
    }

    public void autoIn(Auto a){
        if(!isOccupato()){
            this.occupatoDa = a;
        }
    }

    public void autoOut(){
        this.occupatoDa = null;
    }

    public int getNumero() {
        return numero;
    }

    public Auto getOccupatoDa() {
        return occupatoDa;
    }

    @Override
    public String toString() {
        return "PostoAuto: " + " numero " + numero + " occupato da: " + occupatoDa;
    }
}
