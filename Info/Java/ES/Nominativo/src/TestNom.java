public class TestNom {
    public static void main(String[] args) {
        Nominativo mio;

        mio = new Nominativo();

        mio.setNome("S");
        System.out.println("il nome è: " + mio.getNome());
        mio.setCognome("A");
        System.out.println("Il cognome è: " + mio.getCognome());
        mio.setSesso('F');
        System.out.println("Il sesso è: " + mio.getSesso());
        //mio.setNascita(15, 01, 2016);
        System.out.println("Il giorno di nascita è: " + mio.getGiorno() + " Il mese di nascita è: " + mio.getMese() + " L' anno di nascita è: " + mio.getAnno());

        System.out.println(mio.toString());

        System.out.println("le prime tre iniziali sono: " + mio.iniziali());

        System.out.println("Il codice fiscale è: " + mio.inizialiCF());

        Nominativo tuo = new Nominativo();

        tuo.setNome("Simone");
        tuo.setCognome("Arrigoni");
        tuo.setSesso('m');
        //tuo.setNascita(15, 11, 2019);

        if(mio.isOmocodice(tuo)){
            System.out.println("il codice fiscale è lo stesso");
        }else{
            System.out.println("Il codice fiscale non è lo stesso");
        }


    }
}
