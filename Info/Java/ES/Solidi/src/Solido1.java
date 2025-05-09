public abstract class Solido1 implements FiguraSolida, CorpoSolido {

    private double pesoSpecifico;

    public Solido1(double pesoSpecifico) {
        this.pesoSpecifico = pesoSpecifico;
    }

    public double getPesoSpecifico() {
        return pesoSpecifico;
    }
    
    public void setPesoSpecifico(double pesoSpecifico) {
        this.pesoSpecifico = pesoSpecifico;
    }

    public double getPeso() {
        return getVolume() * pesoSpecifico;
    }
}
