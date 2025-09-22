public class Test {
    public static void main(String[] args) {
        Canzone c1 = new Canzone("il mago", "Giorgis", 125);
        Canzone c2 = new Canzone("Brama che passione", "giorgis", 200);
        Album a1 = new Album("4a", c1);
        a1.addCanzone(c2);
        System.out.println(a1.toString());
    }
}
