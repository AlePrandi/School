public class TestLavoratore {
    public static void main(String[] args) {
        Lavoratore lavoratore = new Lavoratore("a", 2);
        LavoratoriConStraordinariPagati lavStrPag = new LavoratoriConStraordinariPagati("b", 3, 10);
        System.out.println(lavoratore.toString());
        System.out.println(lavStrPag.toString());

        //PROVA DOWN-CASTING E UP-CASTING
        Lavoratore l1, l2;
        LavoratoriConStraordinariPagati lv1, lv2, lv3;

        lv1 = new LavoratoriConStraordinariPagati("ciao", 3 , 5);
        l2 = new Lavoratore("Franco", 2);
        //NON POSSIBILE lv2 = new Lavoratore("Maria", 2);
        l1 = lv1; // UP_CASTING SOTTOINTESO SEMPRE POSSIBILE <-- l1 = (Lavoratore)lv1;
        //lv2 = (LavoratoriConStraordinariPagati) l2;
        lv3 = (LavoratoriConStraordinariPagati) l1;
    }
}