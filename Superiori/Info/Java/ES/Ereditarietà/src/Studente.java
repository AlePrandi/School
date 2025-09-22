public class Studente extends Persona{
    private String matricola;
    private String universita;
    
    public Studente(String nome, String cognome,String codFisc, String matricola, String universita){
        super(nome, cognome,codFisc);
        this.matricola = matricola;
        this.universita = universita;
    }

    public void setMatricola(String matricola){
        this.matricola = matricola;
    }

    public String getMatricola(){
        return matricola;
    }

    public void setUniversita(String universita){
        this.universita = universita;
    }

    public String getUniversita(){
        return universita;
    }

    @Override
    public String toString() {
        return super.toString() + "     matricola: " + matricola + "    universita: " + universita;
    }

}
