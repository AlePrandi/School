public abstract class Solido {
    private double pesoSpecifico;

    public Solido(double peso_spec){
        pesoSpecifico = (peso_spec > 0.0) ? peso_spec : 1.0;
    }

    public double getPesoSpecifico() {
        return pesoSpecifico;
    }

    public abstract double getSuperficie();

    public abstract double getVolume();

    public double getPeso(){
        return pesoSpecifico * getVolume();
    }

}
