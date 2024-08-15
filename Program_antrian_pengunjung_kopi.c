#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

/*
    Nama        : Muhammad Hidayatullah
    Kelas       : B
    NIM         : 2110512066
*/

int inisialisasi();
int empty();
int full();
void enqueue();
void dequeue();
void tampil();
struct queue {
    int data[MAX];
    int depan;
    int belakang;
    char pesanan[MAX][100];
};struct queue antri;


int main(){
    int pilih;
    inisialisasi();
    do{
        printf("MENU OPERASI QUEUE PELANGGAN KAFE\n");
        printf("=================================\n");
        printf("1. Input Data Pelanggan \n");
        printf("2. Pelanggan Dilayani\n");
        printf("3. Tampilkan Data Pelanggan \n");
        printf("4. Keluar dari Aplikasi \n");
        printf("Pilihan Anda ? [1-4] : ");scanf("%d", &pilih);
    switch(pilih){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            tampil();
            break;
        case 4:
            printf("\nKeluar Aplikasi...!!!\n");
            exit(0);
            break;
        default:
            printf("\nMasukkan Pilihan Dari 1-4 !!!\n\n");
            break;
}
}while(pilih>0 && pilih<5);
        //getch();
}
int inisialisasi(){
    antri.depan=antri.belakang=-1;
}

int empty(){
    if(antri.belakang==-1){
        return 1;}
    else{
        return 0;}
    }

int full(){
    if(antri.belakang==(MAX-1)){
        return 1;}
    else{
        return 0;}
}

void enqueue(){
    int data;
    int menu;
    char min[100];
    if(empty()){
        printf("Masukkan Nomor Pelanggan : ");
        scanf("%d", &data);
        getchar();
        printf("MENU JUARA KAFE\n");
        printf("=================================\n");
        printf("Makanan\n");
        printf("1. Pisang Goreng    Rp 2000\n");
        printf("2. Roti Bakar       Rp 14000\n");
        printf("3. Siomay           Rp 10000\n");
        printf("4. Chicken Fingers  Rp 10000\n");
        printf("5. Onion Ring       Rp 9000\n");
        printf("6. Kentang Goreng   Rp 10000\n");
        printf("Minuman\n");
        printf("7. Milk tea         Rp 10000\n");
        printf("8. Ice Blend        Rp 10000\n");
        printf("9. Hot Tea          Rp 8000\n");
        printf("10. Milk Shake      Rp 10000\n");
        printf("11. Flavoured Tea   Rp 9000\n\n");
        printf("Masukkan Menu Yang Ingin di Pesan: ");
        scanf("%d", &menu);
        switch(menu){
        case 1:
            strcpy(min, "Pisang Goreng");
            break;
        case 2:
            strcpy(min, "Roti Bakar");
            break;
        case 3:
            strcpy(min, "Siomay");
            break;
        case 4:
            strcpy(min, "Chicken Fingers");
            break;
        case 5:
            strcpy(min, "Onion Ring");
            break;
        case 6:
            strcpy(min, "Kentang Goreng");
            break;
        case 7:
            strcpy(min, "Milk Tea");
            break;
        case 8:
            strcpy(min, "Ice Blend");
            break;
        case 9:
            strcpy(min, "Hot Tea");
            break;
        case 10:
            strcpy(min, "Milk Shake");
            break;
        case 11:
            strcpy(min, "Flavoured Tea");
            break;
        default:
            printf("Input Anda Kurang Tepat\n");
            break;
        }

        antri.depan=antri.belakang=0;
        antri.data[antri.belakang]=data;
        strcpy(antri.pesanan[antri.belakang], min);
        printf("Pelanggan dengan Nomor %d dan pesanan %s berhasil di masukkan \n", data, antri.pesanan[antri.belakang]);
    }
    else if(full()){
        printf("Data pelanggan sudah penuh..!!!\n");
    }
    else{
        printf("Masukkan Nomor Pelanggan : ");
        scanf("%d", &data);
        getchar();
        printf("MENU JUARA KAFE\n");
        printf("=================================\n");
        printf("Makanan\n");
        printf("1. Pisang Goreng    Rp 2000\n");
        printf("2. Roti Bakar       Rp 14000\n");
        printf("3. Siomay           Rp 10000\n");
        printf("4. Chicken Fingers  Rp 10000\n");
        printf("5. Onion Ring       Rp 9000\n");
        printf("6. Kentang Goreng   Rp 10000\n");
        printf("Minuman\n");
        printf("7. Milk tea         Rp 10000\n");
        printf("8. Ice Blend        Rp 10000\n");
        printf("9. Hot Tea          Rp 8000\n");
        printf("10. Milk Shake      Rp 10000\n");
        printf("11. Flavoured Tea   Rp 9000\n\n");
        printf("Masukkan Menu Yang Ingin di Pesan: ");
        scanf("%d", &menu);
        switch(menu){
        case 1:
            strcpy(min, "Pisang Goreng");
            break;
        case 2:
            strcpy(min, "Roti Bakar");
            break;
        case 3:
            strcpy(min, "Siomay");
            break;
        case 4:
            strcpy(min, "Chicken Fingers");
            break;
        case 5:
            strcpy(min, "Onion Ring");
            break;
        case 6:
            strcpy(min, "Kentang Goreng");
            break;
        case 7:
            strcpy(min, "Milk Tea");
            break;
        case 8:
            strcpy(min, "Ice Blend");
            break;
        case 9:
            strcpy(min, "Hot Tea");
            break;
        case 10:
            strcpy(min, "Milk Shake");
            break;
        case 11:
            strcpy(min, "Flavoured Tea");
        }
        antri.belakang++;
        antri.data[antri.belakang]=data;
        strcpy(antri.pesanan[antri.belakang], min);
        printf("Pelanggan dengan Nomor %d dan pesanan %s berhasil di masukkan \n", data, antri.pesanan[antri.belakang]);
        }
        printf("\n");
}
void dequeue(){
    int temp;
    char m[100];
    if(empty()){
        printf("\nData Dalam Barisan Kosong!!!\n");}
    else{
        temp=antri.data[antri.depan];
        strcpy(m, antri.pesanan[antri.depan]);
        antri.depan++;
        printf("\nPelanggan %d dengan pesanan %s sudah dilayani \n", temp, m);
        }
}
void tampil(){
    int i;
    if(empty()){
        printf("\nData Pelanggan Kosong...!!!\n\n");

    }else{
        for(i=antri.depan; i<=antri.belakang; i++){
            printf("\nPelanggan No: %d Pesanan: %s\n", antri.data[i], antri.pesanan[i]);
    }

        printf("\n");
    }
}
