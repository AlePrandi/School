import java.io.IOException;

public class ErroreElementoInesistente extends IOException { // eccez controllata
    public ErroreElementoInesistente() {
        super("Errore Elemento Inesistente");
    }

    public ErroreElementoInesistente(String stringa) {
        super(stringa);
    }
}
