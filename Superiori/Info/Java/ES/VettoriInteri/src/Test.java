public class Test {
    public static void main(String[] args) {

        /*
         *
         
        VettoreInteri v = new VettoreInteri(2);

        try {
            v.add(6);
            v.add(5);
        } catch (ErroreVettorePieno e) {
            System.out.println(e.getMessage());
        }
        try {
            System.out.println(v.getMin());

        } catch (ErroreVettoreVuoto e) {
            System.out.println(e.getMessage());
        }
        try {
            v.cercaEl(7);
        } catch (ErroreElementoInesistente e) {
            System.out.println(e.getMessage());
        }
        try {
            v.eliminaPrimo(6);
        } catch (ErroreElementoInesistente e) {
            System.out.println(e.getMessage());
        }

        System.out.println(v.toString());

        VettoreInteri v1 = new VettoreInteri("1|2|3|4");
        System.out.println(v1.toString());

        VectorInteri v2 = new VectorInteri();
        v2.add(4);
        v2.add(5);
        System.out.println(v2.toString());
        try {
            System.out.println(v2.getMin());
        } catch (ErroreVettoreVuoto e) {
            System.out.println(e.getMessage());
        }
        try {
            v2.cercaEl(7);
        } catch (ErroreElementoInesistente e) {
            System.out.println(e.getMessage());
        }
        try {
            v2.eliminaPrimo(7);
            System.out.println(v2.toString());
        } catch (ErroreElementoInesistente e) {
            System.out.println(e.getMessage());
        }
        */
        VectorInteri v3 = new VectorInteri("1|2|3");
        System.out.println(v3.toString());

        try {
            v3.elimina(1);
            System.out.println(v3);
            v3.elimina(5);
            System.out.println(v3);
        }catch(ErroreElementoInesistente e) { 
            System.out.println(e.getMessage());
        }

        String s = "123a";
        if (s.matches("[0-9]*")){
            System.out.println("Ok");
        }else{
            System.out.println("Non ok");
        }
    }
}