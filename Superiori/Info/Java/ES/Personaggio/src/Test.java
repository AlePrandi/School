public class Test {
    public static void main(String[] args) {
        Cappello cappello = new Cappello("Cappello", "Rosso");
        Maglia maglia = new Maglia("Maglia", "Giallo");
        Pantalone pantalone = new Pantalone("Pantalone", "Blu");

        Personaggio p1 = new Personaggio("Player", cappello, maglia, pantalone);

        Arma arma1 = new Arma("Spada",18.0,22);
        Arma arma2 = new Arma("Arco", 26,11);

        Personaggio.Arto arto1 = p1.new Arto(10, arma1);
        Personaggio.Arto arto2 = p1.new Arto(8.0, arma2);

        p1.addArto(arto1);
        p1.addArto(arto2);

        Personaggio.Gambe gambe1 = p1.new Gambe(15.0);
        Personaggio.Gambe gambe2 = p1.new Gambe(12.0);

        p1.addGambe(gambe1);
        p1.addGambe(gambe2);

        System.out.println("Personaggio: " + p1.getNome());
        System.out.println(p1.toString());
    }
}
