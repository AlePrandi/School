public class velocita{
    private float velocita;

    public velocita(){
        velocita = 0;
    }

    public float getVelKmH(){
        return velocita;
    }

    public float getVelMS(){
        return velocita / 3.6f;
    }

    public void setVelKmH(float velKmH){
        velocita = velKmH;
    }

    public void setVelMS(float velKmH){
        velocita = getVelMS();
    }

    public String toString(){
        return "Velocita in Km/h: " + getVelKmH() + "\n"
        + "Velocita in m/s: " + getVelMS();
    }

}