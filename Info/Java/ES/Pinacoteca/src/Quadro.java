public class Quadro{
    private String autore;
    private String titolo;
    private Tecnica tecnica;
    private float valore;

    public Quadro(String autore, String titolo, Tecnica tecnica, float valore){
        this.autore = autore;
        this.tecnica = tecnica;
        this.valore = valore;
        this.titolo = titolo;
    }

    public void setAutore(String autore){
        this.autore = autore;
    }

    public String getAutore(){
        return autore;
    }

    public void setTitolo(String titolo){
        this.titolo = titolo;
    }

    public String getTitolo(){
        return titolo;
    }

    public Tecnica getTecnica(){
        return tecnica;
    }

    public void setValore(float valore){
        this.valore = valore;
    }

    public float getValore(){
        return valore;
    }

    public boolean isParagonabile(Quadro q){
        if (q != null){
            if(this.valore == q.getValore() && this.tecnica == q.getTecnica()){
                return true;
            }
        }
        return false;
    }

    public String toString(){
        return "Autore: " + autore + "  Titolo: " + titolo + "  Tecnica: " + tecnica + "  Valore: " + valore;
    }
}