public class Test {
    public static void main(String[] args) {
        try {
         Cerchio c = new Cerchio(-1);             
        }catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
        try {
            CerchioIOException c1 = new CerchioIOException(-1);
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
        finally{
            System.out.println("Passa di qua");
        }
        CerchioRuntimeException c2 = new CerchioRuntimeException(-1);
    }
}
