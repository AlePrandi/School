import java.util.Random;
public class TestSomma {
    public static void main(String[] args) {

        /*
         * int []vett = new int[5];
         * int somma = 0;
         * 
         * for (int k = 0; k < vett.length; k++){
         * vett[k]++;
         * }
         * 
         * for (int el : vett){
         * el++;
         * somma += vett[el];
         * }
         * System.out.println(somma);
         */

        int vett[] = new int[20];
        Random random = new Random();
        for (int k = 0; k < vett.length; k++) {
            vett[k] = random.nextInt(91) + 10;
            for (int j = k; j > 0; j--) {
                if (vett[k] == vett[j])
                    vett[k] = random.nextInt(91) + 10;
            }
        }
        for (int el : vett) {
            System.out.println(vett[el]);
        }
    }
}