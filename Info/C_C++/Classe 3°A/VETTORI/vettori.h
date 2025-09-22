#include <stdbool.h>
#include <time.h>


int chiediDim(int dimMax) {
    int x;
    do {
        printf("inserire la dimensione del vettore[0 e %d]:", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);
    return x;
}

void caricaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("[%d]inserire un numero: ", k);
        scanf("%d", &v[k]);
    }
}

void caricaVettCasuale(int v[], int n, int MIN, int MAX) {
    srand(time(NULL));
    for (int k = 0; k < n; k++) {
        v[k] = MIN + rand() % (MAX + 1 - MIN);
    }
}

void stampaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}

void scambio(int *x, int *y) {
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

void selectionSort(int v[],int n) {
    int k,kmin,j;
    for(k = 0; k < n-1; k++) {
        kmin = k;
        for(j = k+1; j < n; j++) {
            if(v[kmin] > v[j]) // confronti
                kmin = j;

        }
        if(kmin != k)
            scambio(&v[k], &v[kmin]);
    }
    return;
}

void raddoppiaVett(int v[],int v1[], int n) {
    for( int k = 0; k < n; k++) {
        v1[k]= v[k] * 2;
    }
}

void tabellinaVett(int v[],int v1[], int n, int tabell) {
    for( int k = 0; k < n; k++) {
        v1[k]= v[k] * tabell;
    }
}

void fattorialeVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        v[k] = v[k] * k + 1;
    }
}

void potVett(int num,int v[], int n) {
    for(int k = 0; k < n; k++) {
        if ( k == 0)
            v[k] = 1;
        else
            v[k] = num * v[k - 1];
    }
}

void copiaVett(int v[],int v1[], int n, int *n1) {
    int j = 0;
    for( int k = 0; k < n; k++) {
        v1[j]= v[k];
        j++;
        k++;
    }
    *n1 = j;
}

void invertiVett(int v[], int dim) {
    int x;
    int j=dim-1;
    for(int k=0; k<dim/2; k++, j--) {
        scambio(&v[k], &v[j]);
    }
}

void multipliVett(int v[],float *media, int n, int div) {
    *media = 0;
    int somma = 0;
    int nMult = 0;

    for (int k = 0; k < n; k++) {
        if (v[k] % div == 0) {
            somma = somma + v[k];
            nMult++;
        }
    }
    *media = (float) somma / nMult;
}

void calcoloPariDispariVett(int v[], int vP[], int vD[], int n, int *n1, int *n2, int mul) {
    int j = 0;
    int w = 0;
    for (int k = 0; k < n; k++) {
        if (v[k] % mul == 0) {
            vP[j] = v[k];
            j++;
        } else {
            vD[w] = v[k];
            w++;
        }
    }
    *n1 = j;
    *n2 = w;
}

void FibonacciVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        if (k == 0)
            v[k] = 1;
        else if(k == 1)
            v[k] = 1;
        else
            v[k] = v[k - 1] + v[k - 2];
    }
}

void sommaVett(int v[], int n, int *somma) {
    *somma = 0;
    for(int k=0; k<n; k++) {
        *somma = *somma + v[k];
    }
}

void mediaVett(int v[], int n, int *somma, float *media) {
    if(n != 0) {
        *media = (float) *somma / n;
    }
}

float ContrOrdinati(int v[], int n) {
    int k = 1;
    float cresc = -1;
    int num;
    while ((k < n) && (cresc == -1)) {
        num = v[k-1];
        if(v[k] > num)
            cresc = 1;
        else
            k++;
    }
    return cresc;
}

bool ContrOrdinatiBool(int v[], int n) {
    int k = 1;
    float cresc = true;
    int num;
    while ((k < n) && (cresc == true)) {
        num = v[k-1];
        if(v[k] > num)
            cresc = false;
        else
            k++;
    }
    return cresc;
}

bool ContrUgualiBool(int v[], int n) {
    int k = 0;
    int uguali = true;
    int num;
    num = v[k];
    while ((k < n) && (uguali == true)) {
        if (v[k] != num)
            uguali = false;
        else
            k++;
    }
    return uguali;
}

int ContrUguali(int v[], int n) {
    int k = 0;
    int uguali = -1;
    int num;
    num = v[k];
    while ((k < n) && (uguali == -1)) {
        if (v[k] != num)
            uguali = 1;
        else
            k++;
    }
    return uguali;
}

bool RicercaOrdDisBool(int v[], int n, int x, int *tent) {
    *tent=0;
    int k,tro;
    bool ce=true;
    k = 0;
    tro = -1;
    while((k<n) && (tro == -1) && (ce == false)) {
        *tent=*tent+1;
        if(x==v[k]) {
            tro=k;
        } else {
            if(v[k]>x) {
                ce = false;
            } else
                k++;
        }
    }
    return tro;
}

bool RicercaOrdDis(int v[], int n, int x, int *tent) {
    *tent=0;
    int k,tro;
    int ce=-1;
    k = 0;
    tro = -1;
    while((k<n) && (tro == -1) && (ce == -1)) {
        *tent=*tent+1;
        if(x==v[k]) {
            tro=k;
        } else {
            if(v[k]>x) {
                ce = 1;
            } else
                k++;
        }
    }
    return tro;
}

bool RicercaNoDisBool(int v[], int n, int x, int *tent) {
    *tent=0;
    int k=0;
    bool tro=false;
    while(k<n && !tro) {
        *tent=*tent+1;
        if(x==v[k]) {
            tro=true;
        } else {
            k++;
        }
    }
    return tro;

}

int RicercaNoDis(int v[], int n, int x, int *tent) {
    int tro,k;

    *tent=0;
    tro=-1;
    k=0;
    int tentat=0;
    while((k<n) && (tro==-1)) {
        *tent=*tent+1;
        if(x == v[k]) {
            tro = k;
        } else {
            k++;
        }
    }
    return tro;
}

int ricercaBinNonRic(int v[], int n, int x) {
    int p,u,m,tro;
    u = n-1;
    tro=-1;
    while((p <= u)&& tro==-1) {
        m = (p+u)/2;
        if(v[m]==x)
            tro=m;
        else if(v[m] < x)
            p = m+1;
        else
            u = m-1;
    }
    return tro;
}

int NonOrdNonDisg(int v[],int n, int x) {
//vettore non ordinato a elementi non disgiunti restituisce le occorrenze
    int nx,k;
    nx=0;
    for (k=0; k<n; k++) {
        if(x == v[k]) {
            printf("\nL'elemento trovato in posizione %d ", k);
                   nx++;
        }
    }
    return nx; //numero di occorrenze
}

bool ContrSpecVettBool(int v[], int n) {
    int spec = true;
    int j = n-1;
    int k = 0;
    while ((k < n/2) && spec == true) {
        if (v[k] != v[j]) {
            spec = false;
        } else {
            k++;
            j--;
        }
    }
    return spec;
}

int ContrSpecVett(int v[], int n) {
    int spec = -1;
    int j = n-1;
    int k = 0;
    while ((k < n/2) && spec == -1) {
        if (v[k] != v[j]) {
            spec = 1;
        } else {
            k++;
            j--;
        }
    }
    return spec;
}
