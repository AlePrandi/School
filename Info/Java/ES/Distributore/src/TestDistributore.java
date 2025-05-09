public class TestDistributore {
    public static void main(String[] args) {
        
        Carburante benzina = new Carburante();
        Carburante diesel = new Carburante("diesel", 1.3f);
        Carburante gpl = new Carburante("GPL", 1.0f);
        Carburante metano = new Carburante("metano", 1.8f);

        Distributore distributore = new Distributore("Eni", "Via Roma", 8);

        distributore.add(benzina);
        distributore.add(diesel);
        distributore.add(gpl);
        distributore.add(metano);

        System.out.println("Statistiche del Distributore:");
        System.out.println(distributore.getStatistiche());

        distributore.aumenta("diesel", 10);

        System.out.println("Distributore dopo aumento:");
        System.out.println(distributore.getStatistiche());
    }
}
