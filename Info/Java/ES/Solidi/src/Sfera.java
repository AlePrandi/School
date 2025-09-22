import java.lang.Math;
public class Sfera extends Solido1{
    private double raggio;

    public Sfera(double raggio, double pesoSpecifico) {
        super(pesoSpecifico);
        this.raggio = (raggio > 0) ? raggio : 1;
    }

    public double getRaggio() {
        return raggio;
    }

    public double getPeso(){
        return super.getPeso();
    }

    public double getSuperficie() {
        return 4 * Math.PI * Math.pow(raggio,2);
    }

    public double getVolume(){
        return (4 * Math.PI * Math.pow(raggio, 3)) / 3;
    }

    public String toString(){
        return "Raggio: " + raggio + "      Superficie: " + getSuperficie() + "     Volume: " + getVolume();
    }
}
