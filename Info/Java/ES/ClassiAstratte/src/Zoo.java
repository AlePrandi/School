public class Zoo{
    private String nome;
    private final int DIM;
    private int nAnimali;
    private Animale[] gabbie;

    public Zoo(String nome, int max_animali){
        DIM = (max_animali > 0) ? max_animali : 10;
        this.nome = nome;
        nAnimali = 0;
        gabbie = new Animale[DIM];
    }

    public void add(Animale a){
        if(a != null && nAnimali < DIM){
            gabbie[nAnimali] = a;
            nAnimali++;
        }
    }

    public void presentatevi(){
        for (int k = 0; k < nAnimali; k++){
            gabbie[k].miPresento();
            if (gabbie[k] instanceof Cane){
                ((Cane)gabbie[k]).ringhiare();
            }
        }
    }
}
