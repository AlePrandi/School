public class Contatto{
    private String nome;
    private String cognome;
    private String numero;
    private String mail;
    private static final String DEF_NUMERO = "0000000000";

    public Contatto(String nome, String cognome, String numero, String mail){
        this.nome = nome;
        this.cognome = cognome;
        if (numero.length() == 10)
            this.numero = numero;
        else
            this.numero = DEF_NUMERO;
        this.mail = mail;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return nome;
    }

    public void setCognome(String cognome){
        this.cognome = cognome;
    }

    public String getCognome(){
        return cognome;
    }

    public void setNumero(String numero){
        this.numero = numero;
    }

    public String getNumero(){
        return numero;
    }

    public void setMail(String mail){
        this.mail = mail;
    }

    public String getMail(){
        return mail;
    }

    public String toString(){
        return "Nome: " + nome + "  Cognome: " + cognome + "    Numero: " + numero + "  Mail: " + mail;
    }
}