public class Zoo{
    public static void main(String[] argv) {
        Animale[] gabbie = new Animale[2];
        gabbie[0] = new Scoiattolo();
        gabbie[1] = new Cane();
        for (int k = 0; k < gabbie.length; k++) {
            gabbie[k].verso();
            if (gabbie[k] instanceof Cane)
                ((Cane) gabbie[k]).ringhiare(); // downcasting

        }
    }
}
