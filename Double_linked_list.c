#include <stdio.h>
#include <conio.h>
/*
    Nama        : Muhammad Hidayatullah
    Kelas       : B
    NIM         : 2110512066
*/

struct angka{
    struct angka *kiri;
    int data;
    struct angka *kanan;
};

int tambahdata(struct angka **bt,int nilai){
    if(*bt == NULL){
        *bt = (struct angka*) malloc (sizeof(struct angka));
        if(*bt == NULL) return 0;

        (*bt)->kiri = NULL;
        (*bt)->data = nilai;
        (*bt)->kanan = NULL;
        return 1;
    }
    else {
        if (nilai < ((*bt)->data)){
            return tambahdata(&((*bt)->kiri), nilai);
        }
        else {
            return tambahdata(&((*bt)->kanan), nilai);
        }
    }
}

void cetakdata(struct angka *bt){
    if(bt->kiri != NULL){
        cetakdata(bt->kiri);
    }
    if((bt->data != NULL)){
        printf("%d ",bt->data);
    }
    if(bt->kanan != NULL){
        cetakdata(bt->kanan);
    }
}

int main(){
        struct angka *ptr;
        int nilai;
        int berhasil;

        ptr = NULL;
        printf("======================================================\n");
        printf("| Pengurutan Angka Menggunakankan Double Linked List |\n");
        printf("======================================================\n");
        printf("| Masukkan Kumpulan Angka Secara ACAK!               |\n");
       	printf("|(Ketik 0 2x Jika Ingin Mengakhiri Input)            |\n");
       	printf("======================================================\n");

        do{
          	scanf("%d \n", &nilai);
          	berhasil = tambahdata(&ptr,nilai);
          	if (!berhasil){
            	printf("Data gagal dimasukkan:\n");
            	getch();
            	return 0;
          	}
        }while(nilai != 0);

        printf("\nData setelah diurutkan: \n");
        cetakdata(ptr);

        getch();
        return 0;
}
