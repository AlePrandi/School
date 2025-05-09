public class TestNoleeggio {
    public static void main(String[] args) {
        Responsabile Mario = new Responsabile("Mario", "Rossi", "MRARSI96E42A192B", "19/06/1996");
        Autonoleggio Gino = new Autonoleggio("Gino", "Via Roma 10", Mario, 150);
        Veicolo auto1 = new Veicolo(001, "ED206AB", "AUDI", "A3");
        Veicolo auto2 = new Veicolo(002, "GM001AA", "PORSCHE", "911 GT3RS");
        Gino.add(auto1);
        Gino.add(auto2);
        Gino.ricercaTarga("ED206AB");
        System.out.println(Mario.toString());
        System.out.println(Gino.toString());
    }
}
