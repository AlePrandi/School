public class Docente extends Persona{ // si usa extends per dire che la classe è un estensione di un'altra
    private String materia;
    private float salario;

    public Docente(String nome, String cognome,String codFisc, String materia, float salario) {
        super(nome, cognome,codFisc);
        this.materia = materia;
        this.salario = salario;
    }

    public void setMateria(String materia){
        this.materia = materia;
    }

    public String getMateria(){
        return materia;
    }

    public void setSalario(float salario){
        this.salario = salario;
    }

    public float getSalario(){
        return salario;
    }

    public String toString() {
        return super.toString() + "     materia: " + materia + "    salario: " + salario;
    }
}
