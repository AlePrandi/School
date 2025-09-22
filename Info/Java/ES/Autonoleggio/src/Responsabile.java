public class Responsabile {
    private String nome;
    private String cognome;
    private String codFisc;
    private String dataNasc;

    public Responsabile(String nome, String cognome, String codFisc, String dataNasc){
        this.nome = nome;
        this.cognome = cognome;
        this.codFisc = codFisc;
        this.dataNasc = dataNasc;
    }

    public void SetNome(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return nome;
    }

    public void SetCognome(String cognome){
        this.cognome = cognome;
    }

    public String getCognome(){
        return cognome;
    }

    public void SetCodFisc(String codFisc){
        this.codFisc = codFisc;
    }

    public String getCodFisc(){
        return codFisc;
    }

    public void SetData(String dataNasc){
        this.dataNasc = dataNasc;
    }

    public String getDataNasc(){
        return dataNasc;
    }

    public String toString(){
        return "nome: " + nome + ", cognome" + cognome + ", nascita: " + dataNasc + ", codFisc: " + codFisc;
    }

}
