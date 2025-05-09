public class TestEred {
    public static void main(String[] args) {
        Persona p1 = new Persona("mario", "rossi", "MRARSS920301");
        Studente stud = new Studente("andrea", "bianchi", "MARASD","A", "bocconi");
        Docente prof = new Docente("gianni", "grassi", "MAMMOFFA", "italiano", 1000f);
        ElencoPersone elenco = new ElencoPersone(10);

        elenco.add(p1);
        elenco.add(stud);
        elenco.add(prof);

        System.out.println(elenco.toString());
    }
}
