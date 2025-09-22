public class Test {
    public static void main(String[] args) {
        VideotecaVector v1 = new VideotecaVector("Prandi", "Via roma 1");
        Dvd d1 = new Dvd("Fast and furious", 100);
        Cd c1 = new Cd("X2VR",1300,12,4);
        d1.add(Lingue.ITA);
        v1.add(d1);
        v1.add(c1);
        c1.setN_copie(10);
        v1.vendo(0);
        v1.compro(0);
        System.out.println(v1.toString());
    }
}
