public class TestPina {
    public static void main(String[] args){
        Quadro q1 = new Quadro("giorgis", "la mia vita", Tecnica.OLIO, 1f);
        Quadro q2 = new Quadro("brama", "A fuoco", Tecnica.ACQUERELLO, 500f);
        Quadro q3 = new Quadro("sciolla", "spingere", Tecnica.CARBONCINO, 20f);
        Pinacoteca p1 = new Pinacoteca("Il Sedile", 50);

        p1.addQuadro(q1);
        p1.addQuadro(q2);
        p1.addQuadro(q3);

        p1.setPrezzo("la mia vita", 200);

        System.out.println(p1.toString());
    }
}
