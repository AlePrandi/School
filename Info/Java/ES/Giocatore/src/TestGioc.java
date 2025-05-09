public class TestGioc {
    public static void main(String[] args) {
        Giocatore Marco = new Giocatore("Marco", 26, 28, Ruolo.BATTITORE);
        Giocatore Giovanni = new Giocatore("Giovanni", 26, 26, Ruolo.PRIMA_BASE);


        Squadra squadra = new Squadra("Rossi", 8);
        squadra.add(Marco);
        squadra.add(Giovanni);

        System.out.println(squadra.toString());
    }
}
