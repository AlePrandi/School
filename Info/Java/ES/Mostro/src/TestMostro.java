public class TestMostro {
    public static void main(String[] args) {
        Mostro mio = new Mostro("Sciula", 8);
        Mostro tuo = new Mostro("Sporgis", 8);
        System.out.println(mio.toString());
        System.out.println(tuo.toString());
        // mio.setVita(mio.getVita() + 1);
        mio.attDa(tuo);
        mio.gioca(tuo);
    }
}
