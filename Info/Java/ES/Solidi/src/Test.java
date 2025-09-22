public class Test {
    public static void main(String[] args) {
        Cubo c1 = new Cubo(3, 100);
        Sfera s1 = new Sfera(4, 100);
        Cubo c2 = new Cubo(5, 100);
        Sfera s2 = new Sfera(6, 100);
        Solido1[] solido = new Solido1[4];
        solido[0] = c1;
        solido[1] = c2;
        solido[2] = s1;
        solido[3] = s2;

        for (int i = 0; i < 4; i++){
            System.out.println(solido[i].toString());
        }
    }
}
