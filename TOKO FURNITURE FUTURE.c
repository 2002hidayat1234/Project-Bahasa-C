#include<stdio.h>
#include<conio.h>
#include<windows.h>

//Struct
struct barang{
	int perabotan;
};
struct subtotal{
	long int jmlbl1, jmlbl2, jmlbl3, jmlbl4, jmlbl5, jmlbl6, jmlbl7, jmlbl8, jmlbl9, jmlbl10;
	long int totalharga, bayar, kembalian;
};
struct perabotan{
	int Sofa, Meja, Karpet, Gorden, Lemari, Bantalkursi, Jamdinding, Asbak, Mejatv, Lampu;
};
struct perabotan mcmperabotan;
struct barang brg;
struct subtotal sub;

//Variable Global
int i, j, temp;
int range;
char yakin;
char sort;

//Array
int harga[] = {5000000, 1500000, 450000, 150000, 900000, 50000, 25000, 6000, 3000000, 150000};
int size = sizeof(harga)/sizeof(harga[0]);

//Prosedure
void panggilPilihan();
void ulangPilihan();
void penghitungan();
void struk();
void asc();
void desc();
void searchHarga();

//Fungsi
int total(int jmlbl1, int jmlbl2, int jmlbl3, int jmlbl4, int jmlbl5, int jmlbl6, int jmlbl7, int jmlbl8, int jmlbl9, int jmlbl10);

//Program Utama
int main(){
	panggilPilihan();
}

//Prosedure Cari Harga
void searchHarga(){
    printf("> [Ketik '1' Untuk Harga Kisaran Rp 6.000 sampai Rp 999.999]\n> [Ketik '2' Untuk Harga Kisaran Rp 1.000.000 sampai Rp 3.000.000]\n> [Ketik '3' Untuk Harga Lebih Dari Rp 3.000.000]\n\n");
    printf("Input Pilihan: ");
	scanf("%d", &range);
    asc();
    puts("");
    printf("==========================================\n");
    printf("| Barang yang dapat dibeli |    Harga    |\n");
    printf("==========================================\n");
	switch(range){
		case 1: printf("| Asbak\t\t\t   | Rp %d\t |\n", harga[0]);
        		printf("| Jam Dinding\t\t   | Rp %d\t |\n", harga[1]);
        		printf("| Bantal Kursi\t\t   | Rp %d\t |\n", harga[2]);
       		 	printf("| Lampu Meja\t\t   | Rp %d\t |\n", harga[3]);
        		printf("| Dorden Jendela\t   | Rp %d\t |\n", harga[4]);
        		printf("| Karpet\t\t   | Rp %d\t |\n", harga[5]);
        		printf("| Lemari\t\t   | Rp %d\t |\n", harga[6]);
				break;
		case 2: printf("| Meja\t\t           | Rp %d\t |\n", harga[7]);
				break;
    	case 3: printf("| Meja TV\t\t   | Rp %d\t |\n", harga[8]);
	    		printf("| Sofa\t\t\t   | Rp %d\t |\n", harga[9]);
	    		break;
	    default: printf("Masukan Pilihan Yang Benar!!");
	}
    printf("==========================================\n");
    panggilPilihan();
}

//Prosedure Ascending Harga
void asc(){
    for(i=0; i<size; i++){
        for(j=0; j<size-i-1; j++){
            if(harga[j]>harga[j+1]){
                temp = harga[j];
                harga[j] = harga[j+1];
                harga[j+1] = temp;
            }
        }
    }
}

//Prosedure Descending Harga
void desc(){
    for(i=0; i<size; i++){
        for(j=0; j<size-i-1; j++){
            if(harga[j]<harga[j+1]){
                temp = harga[j];
                harga[j] = harga[j+1];
                harga[j+1] = temp;
            }
        }
    }
}

//Prosedure Pemanggilan Sorting Menggunakan Binary Search Tree
void sortHarga(){
    printf("> [Ketik 'A' untuk 'Pengurutan Dari Harga Termurah (Ascending)']\n> [Ketik 'D' untuk 'Pengurutan Dari Harga Termahal (Descending)'] \n");
    printf("Input Pilihan: ");
    scanf("%c", &sort);
    if(sort=='A'|| sort=='a'){
    	system("cls");
        asc();
        puts("=========Pengurutan Dari Harga Termurah=========");
    	printf("=================================================\n");
		printf("| No.| Perabotan Rumah Tangga \t|     Harga\t|\n");
		printf("|------------------------------------------------\n");
		printf("| 1. | Asbak\t\t\t| Rp %d       |\n", harga[0]);
		printf("| 2. | Jam Dinding\t\t| Rp %d      |\n", harga[1]);
		printf("| 3. | Bantal Kursi\t\t| Rp %d      |\n", harga[2]);
		printf("| 4. | Lampu Meja\t\t| Rp %d     |\n", harga[3]);
		printf("| 5. | Gorden Jendela\t\t| Rp %d     |\n", harga[4]);
		printf("| 6. | Karpet\t\t\t| Rp %d     |\n", harga[5]);
		printf("| 7. | Lemari\t\t\t| Rp %d     |\n", harga[6]);
		printf("| 8. | Meja\t\t\t| Rp %d    |\n", harga[7]);
		printf("| 9. | Meja TV\t\t\t| Rp %d    |\n", harga[8]);
		printf("| 10.| Sofa\t\t\t| Rp %d    |\n", harga[9]);
		printf("=================================================\n");
   		panggilPilihan();
    }
    else if(sort=='D'|| sort=='d'){
    	system("cls");
        desc();
        puts("=========Pengurutan Dari Harga Termahal=========");
  	 	printf("=================================================\n");
		printf("| No.| Perabotan Rumah Tangga \t|     Harga\t|\n");
		printf("|------------------------------------------------\n");
		printf("| 1. | Sofa\t\t\t| Rp %d    |\n", harga[0]);
		printf("| 2. | Meja TV\t\t\t| Rp %d    |\n", harga[1]);
		printf("| 3. | Meja\t\t\t| Rp %d    |\n", harga[2]);
		printf("| 4. | Lemari\t\t\t| Rp %d     |\n", harga[3]);
		printf("| 5. | Karpet\t\t\t| Rp %d     |\n", harga[4]);
		printf("| 6. | Gorden Jendela\t\t| Rp %d     |\n", harga[5]);
		printf("| 7. | Lampu Meja\t\t| Rp %d     |\n", harga[6]);
		printf("| 8. | Bantal Kursi\t\t| Rp %d      |\n", harga[7]);
		printf("| 9. | Jam Dinding\t\t| Rp %d      |\n", harga[8]);
		printf("| 10.| Asbak\t\t\t| Rp %d       |\n", harga[9]);
		printf("=================================================\n");
    	panggilPilihan();
    }
}

//Prosedure Daftar Barang
void panggilPilihan(){

	printf("\n=====Selamat Datang di Toko Furniture Future=====\n\n");
	printf("   Silakan Pilih Macam-Macam Perabotan Rumah:\n");
	printf("=================================================\n");
	printf("| No.| Perabotan Rumah Tangga \t|     Harga\t|\n");
	printf("|------------------------------------------------\n");
	printf("| 1. | Sofa\t\t\t| Rp 5.000.000  |\n");
	printf("| 2. | Meja\t\t\t| Rp 1.500.000  |\n");
	printf("| 3. | Karpet\t\t\t| Rp 450.000    |\n");
	printf("| 4. | Gorden Jendela\t\t| Rp 150.000    |\n");
	printf("| 5. | Lemari\t\t\t| Rp 900.000    |\n");
	printf("| 6. | Bantal Kursi\t\t| Rp 50.000     |\n");
	printf("| 7. | Jam Dinding\t\t| Rp 25.000     |\n");
	printf("| 8. | Asbak \t\t\t| Rp 6.000      |\n");
	printf("| 9. | Meja TV\t\t\t| Rp 3.000.000  |\n");
	printf("| 10.| Lampu Meja\t\t| Rp 150.000    |\n");
	printf("=================================================\n");

	printf("=========================\n");
	printf("|99. Struk Pembayaran\t|\n");
	printf("|55. Reset pilihan\t|\n");
	printf("|22. Sorting harga\t|\n");
	printf("|44. Cari kisaran harga\t|\n");
	printf("|00. Keluar\t\t|\n");
	printf("=========================\n");

	for(brg.perabotan != 0; brg.perabotan != 99;){
		printf("\nInput pilihan yang Anda inginkan: ");
		scanf("%d", &brg.perabotan);
			switch(brg.perabotan){
				case 1: printf("[1] Pemesanan Sofa \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Sofa);
						printf("\n===============================================\n");
						sub.jmlbl1 = mcmperabotan.Sofa * harga[0];
						break;
				case 2: printf("[2] Pemesanan Meja \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Meja);
						printf("\n===============================================\n");
						sub.jmlbl2 = mcmperabotan.Meja * harga[1];
						break;
				case 3: printf("[3] Pemesanan Karpet \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Karpet);
						printf("\n===============================================\n");
						sub.jmlbl3 = mcmperabotan.Karpet * harga[2];
						break;
				case 4: printf("[4] Pemesanan Gorden Jendela \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Gorden);
						printf("\n===============================================\n");
						sub.jmlbl4 = mcmperabotan.Gorden * harga[3];
						break;
				case 5: printf("[5] Pemesanan Lemari \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Lemari);
						printf("\n===============================================\n");
						sub.jmlbl5 = mcmperabotan.Lemari * harga[4];
						break;
				case 6: printf("[6] Pemesanan Bantal Kursi \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Bantalkursi);
						printf("\n===============================================\n");
						sub.jmlbl6 = mcmperabotan.Bantalkursi * harga[5];
						break;
				case 7: printf("[7] Pemesanan Jam Dinding \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Jamdinding);
						printf("\n===============================================\n");
						sub.jmlbl7 = mcmperabotan.Jamdinding * harga[6];
						break;
				case 8: printf("[8] Pemesanan Asbak Rokok \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Asbak);
						printf("\n===============================================\n");
						sub.jmlbl8 = mcmperabotan.Asbak * harga[7];
						break;
				case 9: printf("[9] Pemesanan Meja TV \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Mejatv);
						printf("\n===============================================\n");
						sub.jmlbl9 = mcmperabotan.Mejatv * harga[8];
						break;
				case 10: printf("[10] Pemesanan Lampu Meja \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Lampu);
						printf("\n===============================================\n");
						sub.jmlbl10 = mcmperabotan.Lampu * harga[9];
						break;
				case 99: Penghitungan();
						break;
				case 55: system("cls"); //Membuat layar menjadi kosong
                        sub.jmlbl1=0, sub.jmlbl2=0, sub.jmlbl3=0, sub.jmlbl4=0, sub.jmlbl5=0, sub.jmlbl6=0, sub.jmlbl7=0, sub.jmlbl8=0, sub.jmlbl9=0, sub.jmlbl10;//Diubah menjadi nilai 0
                        mcmperabotan.Sofa=0, mcmperabotan.Meja=0, mcmperabotan.Karpet=0, mcmperabotan.Gorden=0, mcmperabotan.Lemari=0, mcmperabotan.Bantalkursi=0, mcmperabotan.Jamdinding=0, mcmperabotan.Asbak=0, mcmperabotan.Mejatv=0, mcmperabotan.Lampu=0;
						panggilPilihan();
                        break;
                case 22: sortHarga();
                        break;
                case 44: searchHarga();
                        break;
				case 00: peyakinan:
                        printf("Apakah anda yakin ingin keluar?\n\n[Input Y untuk Ya]\t[Input T untuk Tidak]\n\n");
                        printf("Input Pilihan: ");
                        scanf("%c", &yakin);
                        if (yakin=='Y'|| yakin=='y'){ //user yakin untuk menutup program
                            system("cls");
                            printf("\t\t- Terima Kasih atas kunjungan Anda -\n\n");
                            system("pause");
                            exit(panggilPilihan);
                        }
                        else if (yakin=='T'|| yakin=='t'){  //user membatalkan penutupan program
                            system("cls");
                            panggilPilihan();
                        }

                        else{  //inputan user bukan Y atau T
                            printf("\nKesalahan inputan\n\n");
                            system("pause");
                            goto peyakinan;
                        }

                		break;
				default:printf("Menu Yang Anda Inputkan Tidak Ada Dalam Daftar\n", brg.perabotan);
						printf("Mohon imput kembali dengan benar!\n");
			}
	}
}

//Prosedure Menampilkan Ulang Daftar Barang
void ulangPilihan(){
	printf("\n===Jika Anda Ingin Memesan Lagi Silahkan Pesan Lagi===\n");
	printf("Silakan Pilih Macam-Macam Perabotan Rumah yang Ada : \n\n");
    printf("=================================================\n");
	printf("| No.| Perabotan Rumah Tangga \t| Harga   \t|\n");
	printf("|------------------------------------------------\n");
	printf("| 1. | Sofa\t\t\t| Rp 5.000.000  |\n");
	printf("| 2. | Meja\t\t\t| Rp 1.500.000  |\n");
	printf("| 3. | Karpet\t\t\t| Rp 450.000    |\n");
	printf("| 4. | Gorden Jendela\t\t| Rp 150.000    |\n");
	printf("| 5. | Lemari\t\t\t| Rp 900.000    |\n");
	printf("| 6. | Bantal Kursi\t\t| Rp 50.000     |\n");
	printf("| 7. | Jam Dinding\t\t| Rp 25.000     |\n");
	printf("| 8. | Asbak \t\t\t| Rp 6.000      |\n");
	printf("| 9. | Meja TV\t\t\t| Rp 3.000.000  |\n");
	printf("| 10.| Lampu Meja\t\t| Rp 150.000    |\n");
	printf("=================================================\n");

	printf("=========================\n");
	printf("|99. Struk Pembayaran\t|\n");
	printf("|55. Reset pilihan\t|\n");
	printf("|22. Sorting harga\t|\n");
	printf("|44. Cari kisaran harga\t|\n");
	printf("|00. Keluar\t\t|\n");
	printf("=========================\n");

	for(brg.perabotan != 0;;){
		printf("\nInput pilihan yang Anda inginkan: ");
		scanf("%d", &brg.perabotan);
			switch(brg.perabotan){
				case 1: printf("[1] Pemesanan Sofa \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Sofa);
						printf("\n===============================================\n");
						sub.jmlbl1 = mcmperabotan.Sofa * harga[0];
						break;
				case 2: printf("[2] Pemesanan Meja \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Meja);
						printf("\n===============================================\n");
						sub.jmlbl2 = mcmperabotan.Meja * harga[1];
						break;
				case 3: printf("[3] Pemesanan Karpet \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Karpet);
						printf("\n===============================================\n");
						sub.jmlbl3 = mcmperabotan.Karpet * harga[2];
						break;
				case 4: printf("[4] Pemesanan Gorden Jendela \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Gorden);
						printf("\n===============================================\n");
						sub.jmlbl4 = mcmperabotan.Gorden * harga[3];
						break;
				case 5: printf("[5] Pemesanan Lemari \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Lemari);
						printf("\n===============================================\n");
						sub.jmlbl5 = mcmperabotan.Lemari * harga[4];
						break;
				case 6: printf("[6] Pemesanan Bantal Kursi \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Bantalkursi);
						printf("\n===============================================\n");
						sub.jmlbl6 = mcmperabotan.Bantalkursi * harga[5];
						break;
				case 7: printf("[7] Pemesanan Jam Dinding \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Jamdinding);
						printf("\n===============================================\n");
						sub.jmlbl7 = mcmperabotan.Jamdinding * harga[6];
						break;
				case 8: printf("[8] Pemesanan Asbak Rokok \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Asbak);
						printf("\n===============================================\n");
						sub.jmlbl8 = mcmperabotan.Asbak * harga[7];
						break;
				case 9: printf("[9] Pemesanan Meja TV \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Mejatv);
						printf("\n===============================================\n");
						sub.jmlbl9 = mcmperabotan.Mejatv * harga[8];
						break;
				case 10: printf("[10] Pemesanan Lampu Meja \n");
						printf("Jumlah pesan = ");
						scanf("%d", &mcmperabotan.Lampu);
						printf("\n===============================================\n");
						sub.jmlbl10 = mcmperabotan.Lampu * harga[9];
						break;
				case 99: Penghitungan();
						break;
				case 55: system("cls"); //Membuat layar menjadi kosong
                        sub.jmlbl1=0, sub.jmlbl2=0, sub.jmlbl3=0, sub.jmlbl4=0, sub.jmlbl5=0, sub.jmlbl6=0, sub.jmlbl7=0, sub.jmlbl8=0, sub.jmlbl9=0, sub.jmlbl10;//Diubah menjadi nilai 0
                        mcmperabotan.Sofa=0, mcmperabotan.Meja=0, mcmperabotan.Karpet=0, mcmperabotan.Gorden=0, mcmperabotan.Lemari=0, mcmperabotan.Bantalkursi=0, mcmperabotan.Jamdinding=0, mcmperabotan.Asbak=0, mcmperabotan.Mejatv=0, mcmperabotan.Lampu=0;
						panggilPilihan();
						break;
                case 22: sortHarga();
                        break;
                case 44: searchHarga();
                        break;
				case 00: peyakinan:
                        printf("Apakah anda yakin ingin keluar?\n\n[Input Y untuk Ya]\t[Input T untuk Tidak]\n\n");
                        printf("Input Pilihan: ");
                        scanf("%c", &yakin);
                        if (yakin=='Y'||yakin=='y'){ //user yakin untuk menutup program
                            system("cls");
                            printf("\t\t- Terima Kasih atas kunjungan Anda -\n\n");
                            system("pause");
                            exit(panggilPilihan);
                        }
                        if (yakin=='T'||yakin=='t'){  //user membatalkan penutupan program
                            system("cls");
                            panggilPilihan();
                        }
                        else{  //inputan user bukan Y atau T
                            printf("\nKesalahan inputan\n\n");
                            system("pause");
                            goto peyakinan;
                        }
                		break;
				default:printf("Menu Yang Anda Inputkan Tidak Ada Dalam Daftar\n", brg.perabotan);
						printf("Mohon imput kembali dengan benar!\n");
			}
	}
}

//Fungsi Total Harga
int total(int jmlbl1, int jmlbl2, int jmlbl3, int jmlbl4, int jmlbl5, int jmlbl6, int jmlbl7, int jmlbl8, int jmlbl9, int jmlbl10){
	int totalharga = sub.jmlbl1 + sub.jmlbl2 + sub.jmlbl3 + sub.jmlbl4 + sub.jmlbl5 + sub.jmlbl6 + sub.jmlbl7 + sub.jmlbl8 + sub.jmlbl9 + sub.jmlbl10;
	return totalharga;
}

//Prosedure Menghitung Harga Barang
void Penghitungan(){
	printf("\n                <Barang Yang Dipesan>\n");
	printf("======================================================\n");
	printf("Jumlah |  Nama Perabotan Rumah Tangga   | Total Harga\n");
	printf("======================================================\n");
	printf("  %d    : Sofa\t\t\t\t: %d\n", mcmperabotan.Sofa, sub.jmlbl1);
	printf("  %d    : Meja   \t\t\t: %d\n", mcmperabotan.Meja, sub.jmlbl2);
	printf("  %d    : Karpet \t\t\t: %d\n", mcmperabotan.Karpet, sub.jmlbl3);
	printf("  %d    : Gorden Jendela  \t\t: %d\n", mcmperabotan.Gorden, sub.jmlbl4);
	printf("  %d    : Lemari  \t\t\t: %d\n", mcmperabotan.Lemari, sub.jmlbl5);
	printf("  %d    : Bantal Kursi   \t\t: %d\n", mcmperabotan.Bantalkursi, sub.jmlbl6);
	printf("  %d    : Jam Dinding  \t\t\t: %d\n", mcmperabotan.Jamdinding, sub.jmlbl7);
	printf("  %d    : Asbak Rokok  \t\t\t: %d\n", mcmperabotan.Asbak, sub.jmlbl8);
	printf("  %d    : Meja TV \t\t\t: %d\n", mcmperabotan.Mejatv, sub.jmlbl9);
	printf("  %d    : Lampu Meja  \t\t\t: %d\n", mcmperabotan.Lampu, sub.jmlbl10);

	//Penghitungan total harga
	printf("======================================================\nTotal Harga adalah = Rp.%d,-\n", total(sub.jmlbl1,sub.jmlbl2,sub.jmlbl3,sub.jmlbl4,sub.jmlbl5,sub.jmlbl6,sub.jmlbl7,sub.jmlbl8,sub.jmlbl9,sub.jmlbl10));
	printf("======================================================\n");

   	bayar:
            printf("\nMasukkan uang bayar = ");
            scanf("%d", &sub.bayar);

            if (sub.bayar >= sub.totalharga){
           		sub.kembalian = sub.bayar - total(sub.jmlbl1,sub.jmlbl2,sub.jmlbl3,sub.jmlbl4,sub.jmlbl5,sub.jmlbl6,sub.jmlbl7,sub.jmlbl8,sub.jmlbl9,sub.jmlbl10);
            	printf("\nKembalian = %d", sub.kembalian);
            }
            else{
                printf("Uang Anda tidak cukup! Silakan input ulang\n");
                goto bayar;
            }

   	printf("\nTekan apa saja untuk melihat struk pembayaran\n");
            system("Pause");
            system("cls");
            struk();

}

//Prosedure Struk Pembelian
void struk(){
	printf("=========================================================================\n");
	printf("|\t\t\tToko Furniture Future			 \t|\n");
	printf("|\t\t\t Jl.Kemakmuran No.3 \t\t\t\t|\n|\t\t\t   Jakarta Barat\t\t\t\t|\n");
	printf("|		\t Telp: 021874523561\t\t\t\t|\n");
	printf("|_______________________________________________________________________|\n");
	printf("| \tNama Barang\t| Harga Satuan\t| Jumlah  |\tTotal   \t|\n");
	printf("|=======================|===============|=========|=====================|\n");

	if(sub.jmlbl1 > 0){
		printf("| Sofa\t\t\t| 5.000.000\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Sofa, sub.jmlbl1);
	}
	if(sub.jmlbl2 > 0){
		printf("| Meja\t\t\t| 1.500.000\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Meja, sub.jmlbl2);
	}
	if(sub.jmlbl3 > 0){
		printf("| Karpet\t\t| 450.000\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Karpet, sub.jmlbl3);
	}
	if(sub.jmlbl4 > 0){
		printf("| Gorden Jendela\t| 150.000\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Gorden, sub.jmlbl4);
	}
	if(sub.jmlbl5 > 0){
		printf("| Lemari\t\t| 900.000\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Lemari, sub.jmlbl5);
	}
	if(sub.jmlbl6 > 0){
		printf("| Bantal Kursi\t\t| 50.000\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Bantalkursi, sub.jmlbl6);
	}
	if(sub.jmlbl7 > 0){
		printf("| Jam Dinding\t\t| 25.000\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Jamdinding, sub.jmlbl7);
	}
	if(sub.jmlbl8 > 0){
		printf("| Asbak rokok\t\t| 6.000\t\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Asbak, sub.jmlbl8);
	}
	if(sub.jmlbl9 > 0){
		printf("| Meja TV\t\t| 3.000.000\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Mejatv, sub.jmlbl9);
	}
	if(sub.jmlbl10 > 0){
		printf("| Lampu Meja\t\t| 150.000\t|    %d\t  | Rp %d\t        |\n", mcmperabotan.Lampu, sub.jmlbl10);
	}
	printf("|_______________________|_______________|_________|_____________________|");
	printf("\n| Total Keseluruhan	= %d         \t\t\t\t|", total(sub.jmlbl1,sub.jmlbl2,sub.jmlbl3,sub.jmlbl4,sub.jmlbl5,sub.jmlbl6,sub.jmlbl7,sub.jmlbl8,sub.jmlbl9,sub.jmlbl10));
	printf("\n| Uang bayar		= %d        \t\t\t\t|", sub.bayar);
	printf("\n| Kembalian             = %d        \t\t\t\t|", sub.kembalian);
	printf("\n=========================================================================\n");
	ulangPilihan();

}



