public class TestRubrica {
    public static void main(String[] args) {
        Rubrica agenda = new Rubrica(150);
        Contatto c1 = new Contatto("Mario","Rossi", "3294994201", "mario.rossi@gmail.com" );
        Contatto c2 = new Contatto("Andrea", "Bianchi", "4020492041", "andrea.bianchi@gmail.com");
        
        agenda.add(c1);
        agenda.add(c2);

        agenda.elencoContatti();
        agenda.cercaContattoNome("Mario", "3666616216");
        agenda.elencoContatti();
    }
}
