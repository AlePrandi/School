public class Veicolo{
    private int codice;
    private String targa;
    private String marca;
    private String modello;

    public Veicolo(int codice, String targa, String marca, String modello){
        this.codice = codice;
        this.targa = targa;
        this.marca = marca;
        this.modello = modello;
    }

    public void setCodice(int codice){
        this.codice = codice;
    }

    public int getCodice(){
        return codice;
    }

    public void setTarga(String targa){
        this.targa = targa;
    }

    public String getTarga(){
        return targa;
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public String getMarca(){
        return marca;
    }

    public void setModello(String modello){
        if(marca != null){
            this.modello = modello;
        }
    }

    public String getModello(){
        return modello;
    }

    public String toString(){
        return "Marca: " + marca + ", modello: " + modello + ", targa: " + targa + ", codice: " + codice;
    }
}