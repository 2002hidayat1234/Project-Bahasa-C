#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define true 1
#define false 0

/*

Proyek UAS Struktur Data & Algoritma
Kelas B

Kelompok 4:
Elmira Ardelia              (2110512046)
Salwa Aisyah Adhani         (2110512052)
Dava Inggriat Hayu Febya    (2110512055)
Muhammad Hidayatullah       (2110512066)
Abiyyah Putri Rahman        (2110512070)

*/

//DEKLARASI STRUCT
//MENYIMPAN INPUTAN MENU YANG DIPILIH
struct pilihan{
    int kendaraan;
};

//DOUBLE LINKED LIST NODE KENDARAAN
struct node{
    //Variabel i dan j bisa untuk harga dan kode, maupun sebaliknya
    float i;
    float j;
    char n[100]; //Nama kendaraan
    struct node *left, *right; //Pointer left dan right subtree
};


//DAFTAR FUNGSI DAN PROSEDUR
    int ambilPilihan(); //Menu utama
    int Urutkan_harga(); //Menu pilihan kendaraan yang ingin diurutkan

    //Menu pilihan jenis kendaraan
    int jenisMobil();
    int jenisMotor();

    //Menu pilihan mencari berdasarkan kode/harga dari masing2 jenis kendaraan
    int mobilModern();
    int mobilKlasik();
    int motorModern();
    int motorKlasik();

    void insertAll(); //Data kendaraan yang dimasukan (insert) ke dalam nodes

    void inOrder(struct node* root); //Prosedur In-Order Traversal (untuk sorting ascending)

    //Print katalog kendaraan
    void PrintMobilModern();
    void PrintMobilKlasik();
    void PrintMotorModern();
    void PrintMotorKlasik();

    //Print hasil sorting berdasarkan harga (ascending)
    void bstHargaMobilModern();
    void bstHargaMobilKlasik();
    void bstHargaMotorModern();
    void bstHargaMotorKlasik();

    //Menginput nilai yang ingin dicari
    //Mobil modern
    void MencariKode1();
    void MencariHarga1();
    //Mobil klasik
    void MencariKode2();
    void MencariHarga2();
    //Motor modern
    void MencariKode3();
    void MencariHarga3();
    //Motor klasik
    void MencariKode4();
    void MencariHarga4();

    //Memilih menu
    struct pilihan pilih;
    //Memasukan data ke nodes
    struct node* insert(struct node* node, float i, char n[100], float j);
    //Mencari kode/harga dengan BST
    struct node *searchkode(struct node *root, float x);
    struct node *searchharga(struct node *root, float x);

//INISIALISASI ROOT MASING-MASING TIPE KENDARAAN
//Tree KODE kendaraan
struct node *root1 = NULL; //Mobil modern
struct node *root2 = NULL; //Mobil klasik
struct node *root3 = NULL; //Motor modern
struct node *root4 = NULL; //Motor klasik

//Tree HARGA kendaraan
struct node *root5 = NULL; //Mobil modern
struct node *root6 = NULL; //Mobil klasik
struct node *root7 = NULL; //Motor modern
struct node *root8 = NULL; //Motor klasik


//PROGRAM PEMANGGIL/UTAMA
int main(){
    insertAll();
    ambilPilihan();
}

//MEMASUKAN SEMUA DATA KENDARAAN KE NODES
void insertAll(){
    //Kode mobil modern
    root1 = insert(root1, 40, "Pajero Sport", 650);
    root1 = insert(root1, 37, "Toyota Alphard", 1550);
    root1 = insert(root1, 39, "Toyota Avanza", 220);
    root1 = insert(root1, 42, "Honda HR-V", 360);
    root1 = insert(root1, 44, "Honda Jazz", 260);
    root1 = insert(root1, 35, "BMW X1 DX", 710);
    root1 = insert(root1, 41, "Mercedes Benz Sedan", 800);
    root1 = insert(root1, 38, "Audi A7", 1900);
    root1 = insert(root1, 43, "Aston Martin Vintage", 5500);
    root1 = insert(root1, 36, "Lamborghini Aventador", 7000);

    //Harga Mobil Modern
    root5 = insert(root5, 650, "Pajero Sport", 40);
    root5 = insert(root5, 1550, "Toyota Alphard", 37);
    root5 = insert(root5, 220, "Toyota Avanza", 39);
    root5 = insert(root5, 360, "Honda HR-V", 42);
    root5 = insert(root5, 260, "Honda Jazz", 44);
    root5 = insert(root5, 710, "BMW X1 DX", 35);
    root5 = insert(root5, 800, "Mercedes Benz Sedan", 41);
    root5 = insert(root5, 1900, "Audi A7", 38);
    root5 = insert(root5, 5500, "Aston Martin Vintage", 43);
    root5 = insert(root5, 7000, "Lamborghini Aventador", 36);

    //-------------------------------------------------------

    //Kode Mobil Klasik
    root2 = insert(root2, 50, "Mini Moris", 500);
    root2 = insert(root2, 47, "Holden Kingswood", 150);
    root2 = insert(root2, 49, "Volkswagen Beetle", 175);
    root2 = insert(root2, 52, "Volkswagen Combi", 120);
    root2 = insert(root2, 54, "Jeeps Willys", 450);
    root2 = insert(root2, 45, "Toyota Corolla", 300);
    root2 = insert(root2, 51, "Jeep Wrangler TJ", 600);
    root2 = insert(root2, 48, "Alfa Romeo Duetto Spider", 750);
    root2 = insert(root2, 53, "Chrysler Imperial Ghia", 270);
    root2 = insert(root2, 46, "Volvo 960", 400);

    //Harga Mobil Klasik
    root6 = insert(root6, 500, "Mini Moris", 50);
    root6 = insert(root6, 150, "Holden Kingswood", 47);
    root6 = insert(root6, 175, "Volkswagen Beetle", 49);
    root6 = insert(root6, 120, "Volkswagen Combi", 52);
    root6 = insert(root6, 450, "Jeeps Willys", 54);
    root6 = insert(root6, 300, "Toyota Corolla", 45);
    root6 = insert(root6, 600, "Jeep Wrangler TJ", 51);
    root6 = insert(root6, 750, "Alfa Romeo Duetto Spider", 48);
    root6 = insert(root6, 270, "Chrysler Imperial Ghia", 53);
    root6 = insert(root6, 400, "Volvo 960", 46);

    //-------------------------------------------------------

    //Kode Motor Modern
    root3 = insert(root3, 70, "Honda CB350", 37.5);
    root3 = insert(root3, 67, "Honda Rebel 300", 51);
    root3 = insert(root3, 69, "Honda Rebel 500 Evo", 80.5);
    root3 = insert(root3, 72, "Yamaha XSR 900", 132);
    root3 = insert(root3, 74, "Yamaha XSR 250", 30);
    root3 = insert(root3, 65, "Suzuki SV650X", 115);
    root3 = insert(root3, 71, "Kawasaki W175", 30.5);
    root3 = insert(root3, 68, "Kawasaki Z900", 29);
    root3 = insert(root3, 73, "Benelli Motobi 200 Evo", 31);
    root3 = insert(root3, 66, "Royal Enfield Classic 650 Twin", 200.5);

    //Harga Motor Modern
    root7 = insert(root7, 37.5, "Honda CB350", 70);
    root7 = insert(root7, 51, "Honda Rebel 300", 67);
    root7 = insert(root7, 80.5, "Honda Rebel 500 Evo", 69);
    root7 = insert(root7, 132, "Yamaha XSR 900", 72);
    root7 = insert(root7, 30, "Yamaha XSR 250", 74);
    root7 = insert(root7, 115, "Suzuki SV650X", 65);
    root7 = insert(root7, 30.5, "Kawasaki W175", 71);
    root7 = insert(root7, 29, "Kawasaki Z900", 68);
    root7 = insert(root7, 31, "Benelli Motobi 200 Evo", 73);
    root7 = insert(root7, 200.5, "Royal Enfield Classic 650 Twin", 66);

    //-------------------------------------------------------

    //Kode Motor Klasik
    root4 = insert(root4, 90, "Benelli Motobi 152", 19.8);
    root4 = insert(root4, 87, "Kawasaki W175", 26.5);
    root4 = insert(root4, 89, "Benelli Motobi 200 Evo", 32.5);
    root4 = insert(root4, 92, "Yamaha XSR 155", 36.5);
    root4 = insert(root4, 94, "Peugeot Django 150 Allure", 50.5);
    root4 = insert(root4, 85, "Cleveland Heist", 55.5);
    root4 = insert(root4, 91, "Cleveland Misfit", 56.5);
    root4 = insert(root4, 88, "Honda Supercub C125", 72.5);
    root4 = insert(root4, 93, "Kawasaki W250", 79.5);
    root4 = insert(root4, 86, "Royal Enfield Classic 350", 81.5);

    //Harga Motor Klasik
    root8 = insert(root8, 19.8, "Benelli Motobi 152", 90);
    root8 = insert(root8, 26.5, "Kawasaki W175", 87);
    root8 = insert(root8, 32.5, "Benelli Motobi 200 Evo", 89);
    root8 = insert(root8, 36.5, "Yamaha XSR 155", 92);
    root8 = insert(root8, 50.5, "Peugeot Django 150 Allure", 94);
    root8 = insert(root8, 55.5, "Cleveland Heist", 85);
    root8 = insert(root8, 56.5, "Cleveland Misfit", 91);
    root8 = insert(root8, 72.5, "Honda Supercub C125", 88);
    root8 = insert(root8, 79.5, "Kawasaki W250", 93);
    root8 = insert(root8, 81.5, "Royal Enfield Classic 350", 86);
}

//MEMBUAT NODE BARU
struct node* newNode(float item, char nama[100], float item1){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> i = item;
    temp -> j = item1;
    strcpy(temp->n, nama);
    temp -> left = temp -> right = NULL;
    return temp;
}


//MEMASUKAN DATA KE DALAM NODE
struct node* insert(struct node* node, float i, char n[100], float j){
    if(node == NULL){
        return newNode(i, n, j);
    }

    if(i < node->i){
        node->left = insert(node->left, i, n, j);
    }else if(i > node->i){
        node->right = insert(node->right, i, n, j);
    }
    return node;
}


//PENCARIAN DATA DENGAN METODE BINARY SEARCH TREE (BST)
//MENCARI DATA BERDASARKAN KODE KENDARAAN
struct node *searchkode(struct node *root, float x){
  //x = kode yang ingin dicari
  if(!root){
    printf("\n------------------------------------------------\n");
    printf("Data tidak ada");
    printf("\n------------------------------------------------\n");

    inputLagi:
    printf("Apakah Anda ingin:\n");
    printf("1. Kembali ke katalog mobil\n");
    printf("2. Kembali ke katalog motor\n");
    printf("3. Kembali ke menu utama\n\n");
    printf("Pilihan anda: ");
    scanf("%d", &pilih.kendaraan);
    switch(pilih.kendaraan){
        case 1: jenisMobil();
                break;
        case 2: jenisMotor();
                break;
        case 3: system("cls");
                ambilPilihan();
                break;
        default: system("cls");
                 printf("Pilihan Anda tidak tersedia, silahkan input kembali\n");
                 goto inputLagi;
    }
  }
  if(root == NULL || root->i == x){
    printf("\n------------------------------------------------\n");
    printf("Kode           = %.1f\nNama Kendaraan = %s\nHarga          = %.1f\n", root->i, root->n, root->j);
    printf("------------------------------------------------\n\n");
  }
  else if(x < root->i){
    return searchkode(root->left, x);
  }
  else{
    return searchkode(root->right, x);
  }
}

//MENCARI DATA BERDASARKAN HARGA KENDARAAN
struct node *searchharga(struct node *root, float x){
  //x = harga yang ingin dicari
  if(!root){
        printf("\n------------------------------------------------\n");
        printf("Data tidak ada");
        printf("\n------------------------------------------------\n");

        inputLagi2:
        printf("Apakah Anda ingin:\n");
        printf("1. Kembali ke katalog mobil\n");
        printf("2. Kembali ke katalog motor\n");
        printf("3. Kembali ke menu utama\n\n");
        printf("Pilihan anda: ");
        scanf("%d", &pilih.kendaraan);
        switch(pilih.kendaraan){
            case 1: jenisMobil();
                    break;
            case 2: jenisMotor();
                    break;
            case 3: system("cls");
                    ambilPilihan();
                    break;
            default: system("cls");
                     printf("Pilihan Anda tidak tersedia, silahkan input kembali\n");
                     goto inputLagi2;
        }
    }
    if(root == NULL || root->i == x){
        printf("\n------------------------------------------------\n");
        printf("Harga          = %.1f\nNama Kendaraan = %s\nKode           = %.1f\n", root->i, root->n, root->j);
        printf("------------------------------------------------\n\n");
    }
    else if(x < root->i){
        return searchharga(root->left, x);
    }
    else{
        return searchharga(root->right, x);
    }
}


//TAMPILAN MENU AWAL
int ambilPilihan(){
    ulangi: //Titik pengulangan di menu utama
    printf("\n=====Selamat Datang di Daydabels Showroom=====\n\n");
	printf(" Silakan Isi Pilihan Anda:\n");
	printf("=================================================\n");
	printf("| No.| Macam-Macam Pilihan \t\t\t|\n");
	printf("|------------------------------------------------\n");
	printf("| 1. | Katalog Mobil\t\t\t\t|\n");
	printf("| 2. | Katalog Motor\t\t\t\t|\n");
	printf("| 3. | Mengurutkan harga termurah\t\t|\n");
	printf("| 4. | Keluar\t\t\t\t\t|\n");
	printf("=================================================\n");
    printf("Pilihan anda: \n");
    scanf("%d", &pilih.kendaraan);
    switch(pilih.kendaraan){
        case 1: jenisMobil();
                break;
        case 2: jenisMotor();
                break;
        case 3: Urutkan_harga();
                break;
        case 4: printf("\nSampai Jumpa Kembali!\n\n");
                exit(0);
        default: system("cls");
                 printf("Pilihan Anda tidak tersedia, silahkan input kembali\n");
                 goto ulangi; //Kembali ke menu utama
    }
}


//IN-ORDER TRAVERSAL UNTUK SORTING DATA
void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("=============================\n\n");
        printf("Kode           = %.1f\nNama Kendaraan = %s\nHarga          = %.1f\n\n", root->i, root->n, root->j);
        inOrder(root->right);
    }
}


//TAMPILAN KATALOG KENDARAAN BERDASARKAN URUTAN KODE
//KATALOG MOBIL MODERN
void PrintMobilModern(){
    printf("                 KATALOG MOBIL MODERN                \n\n");
    printf("=====================================================\n");
    printf("| Kode |         Nama Mobil        |      Harga     |\n");
    printf("=====================================================\n");
    printf("|  35  |   BMW X1 DX               |  710   Juta    |\n");
    printf("|  36  |   Lamborghini Aventador   |  7     Miliar  |\n");
    printf("|  37  |   Toyota Alphard          |  1,550 Miliar  |\n");
    printf("|  38  |   Audi A7                 |  1,9   Miliar  |\n");
    printf("|  39  |   Toyota Avanza           |  220   Juta    |\n");
    printf("|  40  |   Pajero Sport            |  650   Juta    |\n");
    printf("|  41  |   Mercedes Benz Sedan     |  800   Juta    |\n");
    printf("|  42  |   Honda HR-V              |  360   Juta    |\n");
    printf("|  43  |   Aston Martin Vintage    |  5,550 Miliar  |\n");
    printf("|  44  |   Honda Jazz              |  260   Juta    |\n");
    printf("=====================================================\n");
    printf("\n");
}

//KATALOG MOBIL KLASIK
void PrintMobilKlasik(){
    printf("                 KATALOG MOBIL KLASIK               \n\n");
    printf("====================================================\n");
    printf("| Kode |         Nama Mobil           |    Harga   |\n");
    printf("====================================================\n");
    printf("|  45  |   Toyota Corolla DX          |  300 Juta  |\n");
    printf("|  46  |   Volvo 960                  |  400 Juta  |\n");
    printf("|  47  |   Holden Kingswood           |  150 Juta  |\n");
    printf("|  48  |   Alfa Romeo Duetto Spider   |  750 Juta  |\n");
    printf("|  49  |   Volkswagen Beetle          |  175 Juta  |\n");
    printf("|  50  |   Mini Moris                 |  500 Juta  |\n");
    printf("|  51  |   Jeep Wrangler TJ           |  600 Juta  |\n");
    printf("|  52  |   Volkswagen Combi           |  120 Juta  |\n");
    printf("|  53  |   Chrysler Imperial Ghia     |  270 Juta  |\n");
    printf("|  54  |   Jeep Willys                |  450 Juta  |\n");
    printf("====================================================\n");
    printf("\n");
}

//KATALOG MOTOR MODERN
void PrintMotorModern(){
    printf("                   KATALOG MOTOR MODERN                     \n\n");
    printf("============================================================\n");
    printf("| Kode |             Nama Motor             |    Harga     |\n");
    printf("============================================================\n");
    printf("|  65  |   Suzuki SV650X                    |  115   Juta  |\n");
    printf("|  66  |   Royal Enfield Classic 650 Twin   |  200,5 Juta  |\n");
    printf("|  67  |   Honda Rebel 300                  |  51    Juta  |\n");
    printf("|  68  |   Kawasaki Z900                    |  29    Juta  |\n");
    printf("|  69  |   Honda Rebel 500 Evo              |  80,5  Juta  |\n");
    printf("|  70  |   Honda CB350                      |  37,5  Juta  |\n");
    printf("|  71  |   Kawasaki W175                    |  30,5  Juta  |\n");
    printf("|  72  |   Yamaha XSR 900                   |  132   Juta  |\n");
    printf("|  73  |   Benelli Motobi 200 Evo           |  31    Juta  |\n");
    printf("|  74  |   Yamaha XSR 250                   |  30    Juta  |\n");
    printf("============================================================\n");
    printf("\n");
}

//KATALOG MOTOR KLASIK
void PrintMotorKlasik(){
    printf("                   KATALOG MOTOR KLASIK                     \n\n");
    printf("======================================================\n");
    printf("| Kode |             Nama Motor        |    Harga    |\n");
    printf("======================================================\n");
    printf("|  85  |   Cleveland Heist             |  55,5 Juta  |\n");
    printf("|  86  |   Royal Enfield Classic 350   |  81,5 Juta  |\n");
    printf("|  87  |   Kawasaki W175               |  26,5 Juta  |\n");
    printf("|  88  |   Honda Supercub C125         |  72,5 Juta  |\n");
    printf("|  89  |   Benelli Motobi 200 Evo      |  32,5 Juta  |\n");
    printf("|  90  |   Benelli Motobi 152          |  19,8 Juta  |\n");
    printf("|  91  |   Cleveland Misfit            |  56,5 Juta  |\n");
    printf("|  92  |   Yamaha XSR 155              |  36,5 Juta  |\n");
    printf("|  93  |   Kawasaki W250               |  79,5 Juta  |\n");
    printf("|  94  |   Peugeot Django 150 Allure   |  50,5 Juta  |\n");
    printf("======================================================\n");
    printf("\n");
}

//IN-ORDER HARGA MOBIL MODERN
void bstHargaMobilModern(){
    sortingMobilModern:
    printf("\n------------------ MOBIL MODERN ------------------\n\n");
    inOrder(root5);
    printf("\n\n---------------\n");
    printf("00. Kembali\n");
    printf("99. Menu Utama\n");
    printf("\nPilihan Anda: ");
    scanf("%d", &pilih.kendaraan);
    printf("\n");
    switch(pilih.kendaraan){
        case 00: system("cls");
                 Urutkan_harga();
                 break;
        case 99: system("cls");
                 ambilPilihan();
                 break;
        default: system("cls");
                 printf("Pilihan Anda tidak tersedia, silahkan input kembali\n");
                 goto sortingMobilModern;
	}
}

//IN-ORDER HARGA MOBIL KLASIK
void bstHargaMobilKlasik(){
    sortingMobilKlasik:
    printf("\n------------------ MOBIL KLASIK ------------------\n\n");
    inOrder(root6);
    printf("\n\n---------------\n");
    printf("00. Kembali\n");
    printf("99. Menu Utama\n");
    printf("\nPilihan Anda: ");
    scanf("%d", &pilih.kendaraan);
    printf("\n");
    switch(pilih.kendaraan){
        case 00: system("cls");
                 Urutkan_harga();
                 break;
        case 99: system("cls");
                 ambilPilihan();
                 break;
        default: system("cls");
                 printf("Pilihan Anda tidak tersedia, silahkan input kembali\n");
                 goto sortingMobilKlasik;
	}
}


//IN-ORDER HARGA MOTOR MODERN
void bstHargaMotorModern(){
    sortingMotorModern:
    printf("\n------------------ MOTOR MODERN ------------------\n\n");
    inOrder(root7);
    printf("\n\n---------------\n");
    printf("00. Kembali\n");
    printf("99. Menu Utama\n");
    printf("\nPilihan Anda: ");
    scanf("%d", &pilih.kendaraan);
    printf("\n");
    switch(pilih.kendaraan){
        case 00: system("cls");
                 Urutkan_harga();
                 break;
        case 99: system("cls");
                 ambilPilihan();
                 break;
        default: system("cls");
                 printf("Pilihan Anda tidak tersedia, silahkan input kembali\n");
                 goto sortingMotorModern;
	}
}

//IN-ORDER HARGA MOTOR KLASIK
void bstHargaMotorKlasik(){
    sortingMotorKlasik:
    printf("\n------------------ MOTOR KLASIK ------------------\n\n");
    inOrder(root8);
    printf("\n\n---------------\n");
    printf("00. Kembali\n");
    printf("99. Menu Utama\n");
    printf("\nPilihan Anda: ");
    scanf("%d", &pilih.kendaraan);
    printf("\n");
    switch(pilih.kendaraan){
        case 00: system("cls");
                 Urutkan_harga();
                 break;
        case 99: system("cls");
                 ambilPilihan();
                 break;
        default: system("cls");
                 printf("Pilihan Anda tidak tersedia, silahkan input kembali\n");
                 goto sortingMotorKlasik;
	}
}

//MENU SORTING HARGA KENDARAAN
int Urutkan_harga(){
    system("cls");
    ulangiPilihKategori:
    printf("Pilih kategori kendaraan \n");
    printf("=====================\n");
	printf("| No.| Kategori     |\n");
	printf("|--------------------\n");
	printf("| 1. | Mobil Modern |\n");
	printf("| 2. | Mobil Klasik |\n");
	printf("| 3. | Motor Modern |\n");
	printf("| 4. | Motor Klasik |\n");
	printf("| 5. | Kembali      |\n");
	printf("=====================\n");
    printf("Masukkan pilihan anda: \n");
    scanf("%d", &pilih.kendaraan);
    switch(pilih.kendaraan){
        case 1: system("cls");
                bstHargaMobilModern();
                break;
        case 2: system("cls");
                bstHargaMobilKlasik();
                break;
        case 3: system("cls");
                bstHargaMotorModern();
                break;
        case 4: system("cls");
                bstHargaMotorKlasik();
                break;
        case 5: system("cls");
                ambilPilihan();
        default: system("cls");
                 printf("Pilihan Anda tidak tersedia, silahkan input kembali\n");
                 goto ulangiPilihKategori;
    }
}

//MENU KATALOG MOBIL
int jenisMobil(){
    ulangiMobil:
    system("cls");
    printf("=================================================\n");
	printf("| No.| Macam-Macam Katalog Mobil \t\t|\n");
	printf("|------------------------------------------------\n");
	printf("| 1. | Mobil Modern\t\t\t\t|\n");
	printf("| 2. | Mobil Klasik\t\t\t\t|\n");
	printf("| 3. | Kembali ke layar utama\t\t\t|\n");
	printf("=================================================\n");
	printf("Masukkan pilihan anda: \n");
    scanf("%d", &pilih.kendaraan);
	switch(pilih.kendaraan){
        case 1: mobilModern();
                break;
        case 2: mobilKlasik();
                break;
        case 3: system("cls");
                ambilPilihan();
                break;
        default: printf("Pilihan anda salah!!!");
                 goto ulangiMobil;
	}
}

//JIKA MEMILIH MOBIL MODERN
int mobilModern(){
    system("cls");
    PrintMobilModern();

    ulangiMobilModern:
    printf("Mencari Mobil Modern: \n");
    printf("=================================\n");
	printf("|Kode| Metode \t\t\t|\n");
	printf("|--------------------------------\n");
	printf("| 1. | Berdasarkan kode\t\t|\n");
	printf("| 2. | Berdasarkan harga\t|\n");
	printf("| 3. | Kembali\t\t\t|\n");
    printf("=================================\n\n");
    printf("Masukkan pilihan anda: \n");
    scanf("%d", &pilih.kendaraan);
    switch(pilih.kendaraan){
        case 1: MencariKode1();
                goto ulangiMobilModern;
        case 2: MencariHarga1();
                goto ulangiMobilModern;
        case 3: jenisMobil();
                break;
        default: printf("Pilihan anda salah!!!");
                 goto ulangiMobilModern;
    }
}

//INPUT KODE MOBIL MODERN YANG INGIN DICARI
void MencariKode1(){
    float cari=0;
    printf("Masukkan kode mobil yang ingin dicari\n\n");
    scanf("%f", &cari);
    searchkode(root1, cari);
}

//INPUT HARGA MOBIL MODERN YANG INGIN DICARI
void MencariHarga1(){
    float cari5=0;
    printf("Masukkan harga mobil yang ingin dicari\n\n");
    scanf("%f", &cari5);
    searchharga(root5, cari5);
}


//JIKA MEMILIH MOBIL KLASIK
int mobilKlasik(){
    system("cls");
    PrintMobilKlasik();

    ulangiMobilKlasik:
    printf("Mencari Mobil Klasik: \n");
    printf("=================================\n");
	printf("|Kode| Metode \t\t\t|\n");
	printf("|--------------------------------\n");
	printf("| 1. | Berdasarkan kode\t\t|\n");
	printf("| 2. | Berdasarkan harga\t|\n");
	printf("| 3. | Kembali\t\t\t|\n");
    printf("=================================\n\n");
    printf("Masukkan pilihan anda: \n");
    scanf("%d", &pilih.kendaraan);
    switch(pilih.kendaraan){
        case 1: MencariKode2();
                goto ulangiMobilKlasik;
        case 2: MencariHarga2();
                goto ulangiMobilKlasik;
        case 3: jenisMobil();
                break;
        default: printf("Pilihan anda salah!!!");
                 goto ulangiMobilKlasik;
    }
}

//INPUT KODE MOBIL KLASIK YANG INGIN DICARI
void MencariKode2(){
    float cari=0;
    printf("Masukkan kode mobil yang ingin dicari\n");
    scanf("%f", &cari);
    searchkode(root2, cari);
}

//INPUT HARGA MOBIL KLASIK YANG INGIN DICARI
void MencariHarga2(){
    float cari6=0;
    printf("Masukkan harga mobil yang ingin dicari\n");
    scanf("%f", &cari6);
    searchharga(root6, cari6);
}


//MENU KATALOG MOTOR
int jenisMotor(){
    ulangiMotor:
    system("cls");
    printf("=================================================\n");
	printf("| No.| Macam-Macam Katalog Motor \t\t|\n");
	printf("|------------------------------------------------\n");
	printf("| 1. | Motor Modern\t\t\t\t|\n");
	printf("| 2. | Motor Klasik\t\t\t\t|\n");
	printf("| 3. | Kembali ke layar utama\t\t\t|\n");
	printf("=================================================\n");
	printf("Masukkan pilihan anda: \n");
	scanf("%d", &pilih.kendaraan);
	switch(pilih.kendaraan){
        case 1: motorModern();
                break;
        case 2: motorKlasik();
                break;
        case 3: system("cls");
                ambilPilihan();
                break;
        default: printf("Pilihan anda salah!!!");
                 goto ulangiMotor;
	}
}

//JIKA MEMILIH MOTOR MODERN
int motorModern(){
    system("cls");
    PrintMotorModern();

    ulangiMotorModern:
    printf("Mencari Motor Modern: \n");
    printf("=================================\n");
	printf("|Kode| Metode \t\t\t|\n");
	printf("|--------------------------------\n");
	printf("| 1. | Berdasarkan kode\t\t|\n");
	printf("| 2. | Berdasarkan harga\t|\n");
	printf("| 3. | Kembali\t\t\t|\n");
    printf("=================================\n\n");
    printf("Masukkan pilihan anda: \n");
    scanf("%d", &pilih.kendaraan);
    switch(pilih.kendaraan){
        case 1: MencariKode3();
                goto ulangiMotorModern;
        case 2: MencariHarga3();
                goto ulangiMotorModern;
        case 3: jenisMotor();
        default: printf("Pilihan anda salah!!!");
                 goto ulangiMotorModern;
    }
}

//INPUT KODE MOTOR MODERN YANG INGIN DICARI
void MencariKode3(){
    float cari=0;
    printf("Masukkan kode motor yang ingin dicari\n");
    scanf("%f", &cari);
    searchkode(root3, cari);
}

//INPUT HARGA MOTOR MODERN YANG INGIN DICARI
void MencariHarga3(){
    float cari7=0;
    printf("Masukkan harga motor yang ingin dicari\n");
    scanf("%f", &cari7);
    searchharga(root7, cari7);
}


//JIKA MEMILIH MOTOR KLASIK
int motorKlasik(){
    system("cls");
    PrintMotorKlasik();

    ulangiMotorKlasik:
    printf("Mencari Motor Klasik: \n");
    printf("=================================\n");
	printf("|Kode| Metode \t\t\t|\n");
	printf("|--------------------------------\n");
	printf("| 1. | Berdasarkan kode\t\t|\n");
	printf("| 2. | Berdasarkan harga\t|\n");
	printf("| 3. | Kembali\t\t\t|\n");
    printf("=================================\n\n");
    printf("Masukkan pilihan anda: \n");
    scanf("%d", &pilih.kendaraan);
    switch(pilih.kendaraan){
        case 1: MencariKode4();
                goto ulangiMotorKlasik;
        case 2: MencariHarga4();
                goto ulangiMotorKlasik;
        case 3: jenisMotor();
        default: printf("Pilihan anda salah!!!");
                 goto ulangiMotorKlasik;
	}
}

//INPUT KODE MOTOR KLASIK YANG INGIN DICARI
void MencariKode4(){
    float cari=0;
    printf("Masukkan kode motor yang ingin dicari\n");
    scanf("%f", &cari);
    searchkode(root4, cari);
}

//INPUT HARGA MOTOR KLASIK YANG INGIN DICARI
void MencariHarga4(){
    float cari8=0;
    printf("Masukkan harga motor yang ingin dicari\n");
    scanf("%f", &cari8);
    searchharga(root8, cari8);
}
