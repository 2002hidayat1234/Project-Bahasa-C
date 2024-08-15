#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j, k;
int nip[100];
char nama[100][18];
void bubble_sort(int bnyk);
void display_arr(int byk);
void selection_sort(int byk);

/*
a. Metode pengurutan dapat dipilih.

b. Pengurutan dapat dipilih secara urut naik atau turun.

c. Pengurutan dapat dipilih berdasarkan NIP dan NAMA.

d. Gunakan struktur data array.
*/
int main(){

    int a;
    start:
    printf("Berapa banyak data karyawan yang ingin dimasukkan: ");
    scanf("%d", &a);
    getchar();
    char n[100];


    for(i=0; i<a; i++){
        printf("Data karyawan ke -%d\n", i+1);
        printf("NIP :  ");
        scanf("%d", &nip[i]);
        getchar();
        printf("Nama:  ");
        fgets(n, 100, stdin);
        strcpy(nama[i], n);
        printf("\n");

    }

    system("cls");
    memilih_sorting:
    printf("Sebelum di sorting\n");
    display_arr(a);


    int p;

    printf("Pilih metode sorting: \n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    scanf("%d", &p);
    if(p == 1){
        bubble_sort(a);
    }else if(p==2){
        selection_sort(a);
    }else{
        system("cls");
        printf("Ulangi!!\n\n");
        goto memilih_sorting;
    }

    printf("\nSetelah disorting: \n");
    display_arr(a);

    int ulg;
    printf("Mau mengulang lagi? \n1)Mulai lagi  2)Exit\n");
    scanf("%d", &ulg);
    if(ulg == 1){
        system("cls");
        goto start;
    }else{
        system("exit");
    }
}

void bubble_sort(int bnyk){
    int temp;
    char b[100];
    int pil;
    int pil1;


    ulangi:
    printf("Disorting berdasarkan nip(ketik 1) atau nama(ketik 2): \n");
    scanf("%d", &pil1);
    if(pil1 == 1){
        ulangi_pil1:
        printf("Dilakukan secara ascending(ketik 1) atau descending(ketik 2):\n");
        scanf("%d", &pil);
        if(pil == 1){
            for(j=0; j<bnyk; j++){
                for(i=0; i<bnyk-1-j; i++){
                    if(nip[i]>nip[i+1]){
                        temp=nip[i];
                        nip[i] = nip[i+1];
                        nip[i+1] = temp;

                        strcpy(b, nama[i]);
                        strcpy(nama[i], nama[i+1]);
                        strcpy(nama[i+1], b);
                    }
                }
            }
        }else if(pil == 2){
            for(j=0; j<bnyk; j++){
                for(i=0; i<bnyk-1-j; i++){
                    if(nip[i]<nip[i+1]){
                        temp=nip[i];
                        nip[i] = nip[i+1];
                        nip[i+1] = temp;

                        strcpy(b, nama[i]);
                        strcpy(nama[i], nama[i+1]);
                        strcpy(nama[i+1], b);
                    }
                }
            }
        }
       else{
            system("cls");
            printf("Ulangii!!\n\n");
            goto ulangi_pil1;
        }
    }else if(pil1 == 2){
        ulangi_pil2:
        printf("Dilakukan secara ascending(ketik 1) atau descending(ketik 2):\n");
        scanf("%d", &pil);
        if(pil == 1){
            for(j=0; j<bnyk; j++){
                for(i=0; i<bnyk-1-j; i++){
                    if(strcmp(nama[i], nama[i+1])>0){
                        temp=nip[i];
                        nip[i] = nip[i+1];
                        nip[i+1] = temp;

                        strcpy(b, nama[i]);
                        strcpy(nama[i], nama[i+1]);
                        strcpy(nama[i+1], b);
                    }
                }
            }
        }else if(pil == 2){
            for(j=0; j<bnyk; j++){
                for(i=0; i<bnyk-1-j; i++){
                    if(strcmp(nama[i], nama[i+1])<0){
                        temp=nip[i];
                        nip[i] = nip[i+1];
                        nip[i+1] = temp;

                        strcpy(b, nama[i]);
                        strcpy(nama[i], nama[i+1]);
                        strcpy(nama[i+1], b);
                    }
                }
            }
        }else{
            system("cls");
            printf("Invalid!!");
            goto ulangi_pil2;

        }
    }else{
        system("cls");
        printf("Invalid!!\n\n");
        goto ulangi;
    }

}


void selection_sort(int byk){
    int pil, pil1;
    int min_idx;
    ulangi_selection:
    printf("Disorting berdasarkan nip(ketik 1) atau nama(ketik 2): \n");
    scanf("%d", &pil1);
    if(pil1 == 1){
        ulangi_pil:
        printf("Dilakukan secara ascending(ketik 1) atau descending(ketik 2):\n");
        scanf("%d", &pil);
        if(pil == 1){
            for(i=0; i<byk-1; i++){
                min_idx = i;
                for(j=i+1; j<byk; j++)
                    if(nip[j]<nip[min_idx])
                        min_idx = j;

                int temp = nip[min_idx];
                char b[100];
                strcpy(b, nama[min_idx]);
                nip[min_idx] = nip[i];
                strcpy(nama[min_idx], nama[i]);
                nip[i] = temp;
                strcpy(nama[i], b);
        }
        }else if(pil == 2){
            for(i=0; i<byk-1; i++){
                min_idx = i;
                for(j=i+1; j<byk; j++)
                    if(nip[j]>nip[min_idx])
                        min_idx = j;

                int temp = nip[min_idx];
                char b[100];
                strcpy(b, nama[min_idx]);
                nip[min_idx] = nip[i];
                strcpy(nama[min_idx], nama[i]);
                nip[i] = temp;
                strcpy(nama[i], b);
            }


        }else{
            system("cls");
            printf("Invalid input!!\n\n");
            goto ulangi_pil;

        }
    }else if(pil1 == 2){
        ulangi_pilihan:
        printf("Dilakukan secara ascending(ketik 1) atau descending(ketik 2):\n");
        scanf("%d", &pil);
        if(pil == 1){
            for(i=0; i<byk-1; i++){
                min_idx = i;
                for(j=i+1; j<byk; j++)
                    if(strcmp(nama[j], nama[min_idx])<0)
                        min_idx = j;

                int temp = nip[min_idx];
                char b[100];
                strcpy(b, nama[min_idx]);
                nip[min_idx] = nip[i];
                strcpy(nama[min_idx], nama[i]);
                nip[i] = temp;
                strcpy(nama[i], b);
        }
        }else if(pil == 2){
            for(i=0; i<byk-1; i++){
                min_idx = i;
                for(j=i+1; j<byk; j++)
                    if(strcmp(nama[j], nama[min_idx])>0)
                        min_idx = j;

                int temp = nip[min_idx];
                char b[100];
                strcpy(b, nama[min_idx]);
                nip[min_idx] = nip[i];
                strcpy(nama[min_idx], nama[i]);
                nip[i] = temp;
                strcpy(nama[i], b);
            }


        }else{
            system("cls");
            printf("Invalid input!!\n\n");
            goto ulangi_pilihan;
        }
    }else{
        system("cls");
        printf("Invalid input!!\n\n");
        goto ulangi_selection;
    }

}

void display_arr(int byk){
    for(i=0; i<byk; i++){
        printf("NIP: %d\n", nip[i]);
        printf("Nama: %s\n\n", nama[i]);
    }


}


















































































