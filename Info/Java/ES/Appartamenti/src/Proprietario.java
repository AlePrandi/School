import java.util.Vector;

public class Proprietario {
    private String nome;
    private double valoreImmobiliare;
    private Vector <Palazzo.Piano.Appartamento> vApp;
    
    public Proprietario(String nome, double valoreImmobiliare) {
        this.nome = nome;
        this.valoreImmobiliare = valoreImmobiliare;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getValoreImmobiliare() {
        return valoreImmobiliare;
    }

    public void setValoreImmobiliare(double valoreImmobiliare) {
        this.valoreImmobiliare = valoreImmobiliare;
    }

    public void addAppartamento(Palazzo.Piano.Appartamento a){
        if (a != null){
            vApp.add(a);
        }
    } 

    @Override
    public String toString() {
        return "Proprietario [nome=" + nome + ", valoreImmobiliare=" + valoreImmobiliare + "]";
    }

}
