import java.util.Vector;

public class Porto {
    private String nome;
    private String localita;
    private Vector<Molo> moli;
    
    public Porto(String nome, String localita, Molo molo) {
        this.nome = nome;
        this.localita = localita;
        this.moli = new Vector<>();
        moli.add(molo);
    }
    
    public void addMolo(Molo molo) {
        moli.add(molo);
    }

    public void passatoGiorno(){
        for(int k=0; k< moli.size(); k++){
            moli.get(k).passatoGiorno();
        }
    }
    
    public String getNome() {
        return nome;
    }

    public String getLocalita() {
        return localita;
    }

    public String postiLiberi(Barca b){
        String str = "";
        for (Molo m : moli){
            if (b.getLarg() <= m.getLarg_max() && b.getLung() <= m.getLung_max()){
                for(int k = 0; k < m.getBarche().size(); k++){
                    if (m.getBarche().get(k).isOccupato() != true){
                        str += m.getBarche().get(k).toString();
                    }
                }
            }
        }
        return str;
    }

    @Override
    public String toString() {
        return "Porto [nome=" + nome + ", localita=" + localita + ", moli=" + moli + "]";
    }   
}
