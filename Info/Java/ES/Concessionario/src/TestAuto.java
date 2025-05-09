public class TestAuto {
    public static void main(String[] args) {
        Auto auto1 = new Auto("audi", "rosso", 15000);
        Auto auto2 = new Auto("mercedes", "grigio", 20000);
        Auto auto3 = new Auto("volvo", "blu", 36000);
        Auto auto4 = new Auto("bmw", "nero", 28100);
        Concessionaria concessionaria = new Concessionaria("Gino", 250);
        concessionaria.add(auto1);
        concessionaria.add(auto2);
        concessionaria.add(auto3);
        concessionaria.add(auto4);
        System.out.println(concessionaria.toString());
        System.out.println("Valore totale auto: " + concessionaria.getSommaPrezzi());
        concessionaria.getColoriAutoModello("audi");
    }
    
}
