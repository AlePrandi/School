public class VettoreInteri {
    private final int DIM;
    private int[] vInteri;
    private int nInteri;
    private static final int DEF_DIM = 1;

    public VettoreInteri() {
        DIM = 1;
        vInteri = new int[DIM];
        nInteri = 0;
    }

    public VettoreInteri(int dimensione) {
        if (dimensione > 0)
            DIM = dimensione;
        else
            DIM = DEF_DIM;
        vInteri = new int[DIM];
        nInteri = 0;
    }

    public VettoreInteri(String elementi) throws NumberFormatException {
        String[] elementiCorretti = elementi.split("\\|");
        DIM = elementiCorretti.length;
        vInteri = new int[DIM];
        for (int k = 0; k < DIM; k++) {
            try {
                vInteri[k] = Integer.parseInt(elementiCorretti[k]);
            } catch (NumberFormatException e) {
                throw new NumberFormatException("Elemento non valido: " + elementiCorretti[k]);
            }
        }
    }

    public void add(int elemento) throws ErroreVettorePieno {
        if (nInteri < DIM) {
            vInteri[nInteri] = elemento;
            nInteri++;
        } else {
            throw new ErroreVettorePieno();
            // throw new ErroreVettorePieno("hai raggiunto il valore massimo");
        }
    }

    public int getMin() {
        if (nInteri > 0) {
            int min = vInteri[0];
            for (int k = 1; k < nInteri; k++) {
                if (vInteri[k] < min)
                    min = vInteri[k];
            }
            return min;
        } else {
            throw new ErroreVettoreVuoto();
        }
    }

    public int cercaEl(int elemento) throws ErroreElementoInesistente {
        int tro = -1;
        int k = 0;
        while (k < nInteri && tro == -1) {
            if (vInteri[k] == elemento)
                tro = k;
            else
                k++;
        }
        if (tro != -1)
            return tro;
        else
            throw new ErroreElementoInesistente();
    }

    public void eliminaPrimo(int elemento) throws ErroreElementoInesistente {
        int pos = cercaEl(elemento);
        for (int k = pos; k < nInteri - 1; k++) {
            vInteri[k] = vInteri[k + 1];
        }
        vInteri[nInteri - 1] = 0;
    }

    @Override
    public String toString() {
        String str = "";
        for (int k : vInteri) {
            str += k + "|";
        }
        return str;
    }
}
