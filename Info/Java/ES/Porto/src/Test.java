public class Test {
    public static void main(String[] args) {
        Molo molo1 = new Molo(1, 10.0, 50.0, 15.0);
        Porto porto = new Porto("Porto di Genova", "Genova", molo1);


        porto.addMolo(molo1);

    }
}
