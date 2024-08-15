#include <stdio.h>
#define true 1
#define false 0

/*
    Nama    : Muhammad Hidayatullah
    Kelas   : B
    NIM     : 2110512066
*/

int main(){
    int n, m;
    int angka[100], kiri, kanan;
    int tengah, temp, key;
    int ketemu = false;

    printf("==============================================\n");
    printf("|        PROGRAM BINARY SEARCH MENGGUNAKAN C  |\n");
    printf("==============================================\n");
    printf("Masukan jumlah data : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Angka ke - [%d] : ", i);
        scanf("%d", &angka[i]);
    }

    for (int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(angka [j] > angka [j+1]){
                temp=angka[j];
                angka[j]=angka[j+1];
                angka[j+1]=temp;
            }
        }
    }

    printf("\nMasukan berapa angka yang ingin dicari : ");
    scanf("%d", &m);

    for(int i=0; i<m; i++){
        printf("\nMasukan angka yang ingin dicari : ");
        scanf("%d", &key);

        kiri = 0;
        kanan = n-1;

        while(kiri<=kanan){
            tengah=(kiri + kanan)/2;
            if(key == angka[tengah]){
                ketemu=true;
                break;
            }else if (key < angka[tengah]){
                kanan = tengah - 1;
            }
            else{
                kiri = tengah + 1;
            }
        }

        for(int i=0; i<n; i++){
            printf("Angka ke - [%d] : %d\n", i, angka[i]);
            if(angka[i]==key){
                ketemu = true;
                printf("\nData ditemukan pada angka ke - [%d]\n", i);
                break;
            }
        }

        if(ketemu==false){
            printf("\nData tidak ditemukan!!!\n");
            break;
        }
    }
   return 0;
}
