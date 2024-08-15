#include<stdio.h>
/*
    Nama    : Muhammad Hidayatullah
    NIM     : 2110512066
    Kelas   : B
*/
int matriks[20][20];
void tunjukkan_matrix(int v);
void tambah_edge(int u, int v, int berat);

int main(){
    int i, j;
    int n, m, asal, tujuan, berat;
    printf("masukkan jumlah simpul : ");
    scanf("%d",&n);
    printf("masukkan jumlah sisi : ");
    scanf("%d",&m);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            matriks[i][j]=0;
        }
    }
    for(i=1; i<=m; i++){
        printf("simpul asal : ");
        scanf("%d",&asal);
        printf("simpul tujuan : ");
        scanf("%d",&tujuan);
        printf("bobot : ");
        scanf("%d",&berat);
        tambah_edge(asal,tujuan,berat);
    }
    tunjukkan_matrix(n);
    return 0;
}


void tunjukkan_matrix(int v){
    int i, j;
    for(i = 1; i <= v; i++){
        for(j = 1; j <= v; j++){
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }
}

void tambah_edge(int u, int v, int berat){
    matriks[u][v] = berat;
}
