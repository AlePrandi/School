public class Test {
    public static void main(String[] args) {
        Libro l1 = new Libro("harry potter", "pino", Generi.ROMANZO, 200, 18f);
        Libro l2 = new Libro("Sherlock holmes", "gino", Generi.GIALLO, 245, 21.3f);
        //Libreria g = new Libreria("Libraccio", "Cuneo", 2500);
        LibreriaVector g = new LibreriaVector("Libraccio", "Cuneo");
        g.addEl(l1);
        g.addEl(l2);
        if (l1.compareTo(l2) == -1)
            System.out.println(l1.getTitolo() + " e piu costoso di " + l2.getTitolo());
        if (l1.compareTo(l2) == 0)
            System.out.println(l1.getTitolo() + " e " + l2.getTitolo() + " hanno lo stesso prezzo");
        if (l1.compareTo(l2) == 1)
            System.out.println(l2.getTitolo() + " e piu costoso di " + l1.getTitolo());
        g.Statistica();
        System.out.println(g.toString());
        g.Statistica2();
    }
}
