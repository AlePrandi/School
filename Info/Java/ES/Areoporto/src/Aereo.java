public abstract class Aereo {
    private String sigla;
    public Aereo(String sigla){
        this.sigla=sigla;
    }

    public String getSigla() {
        return sigla;
    }

    public boolean uguale(Aereo a){
        if(this.sigla.equals(a.getSigla())){
            return true;
        }else{
            return false;
        }
    }
    public String toString(){
        return "Sigla: " + sigla;
    }
}
