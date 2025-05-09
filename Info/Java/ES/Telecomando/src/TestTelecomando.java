public class TestTelecomando {
    public static void main(String[] args){
        Telecomando telecomando = new Telecomando(100, 999);
        telecomando.setCanale(5);
        telecomando.setVolume(25);
        System.out.println(telecomando.toString());
    }
}
