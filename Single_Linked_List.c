#include<stdio.h>
#include<stdlib.h>

/*
    Nama        : Muhammad Hidayatullah
    Kelas       : B
    NIM         : 2110512066
*/
struct node{
    int info;
    struct node *link;
};
void display(struct node *start);
struct node *addatbeg(struct node *start,int num);
void addtend(struct node *start,int num);
void addafter(struct node *start,int num, int num2);
struct node *addbefore(struct node *start,int num, int num2);
struct node *del(struct node *start,int num);
void search(struct node *start,int num2);
void count(struct node *start);
main(){
    struct node *start=NULL;
    int choice,num,num2;
    while(1){
        printf("\n\n1. Display\n");
        printf("2. Add node to empty list\n");
        printf("3. Add node at the end\n");
        printf("4. Add after\n");
        printf("5. Add before\n");
        printf("6. Delete from list\n");
        printf("7. Exit\n");
        printf("Masukan pilihan : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            display(start);
            break;
        case 2://awal
            printf("Masukkan angka : ");
            scanf("%d",&num);
            start = addatbeg(start, num);
            break;
        case 3://akhir
            printf("Masukkan angka : ");
            scanf("%d",&num);
            addtend(start, num);
            break;
        case 4://tengah
            printf("Masukkan angka : ");
            scanf("%d",&num);
            printf("Masukkan angka ke-2 : ");
            scanf("%d",&num2);
            addafter(start, num, num2);
            break;
        case 5:
            printf("Masukkan angka : ");
            scanf("%d",&num);
            printf("Masukkan angka ke-2 : ");
            scanf("%d",&num2);
            start = addbefore(start, num,num2);
            break;
        case 6:
            printf("Masukkan angka untuk dihapus : ");
            scanf("%d",&num);
            start = del(start, num);
            break;
        case 7:
            exit(1);
        default:
            printf("silahkan masukkan pilihan lain");
        }
    }
}

void display(struct node *start){
    struct node *p;
    if(start==NULL){
        printf("Tidak ada isi\n");
        return;
    }
    p = start;
    while(p != NULL){
        printf("%d\t", p->info);
        p=p->link;
    }
}

struct node *addatbeg(struct node *start, int num){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=num;
    temp->link = start;
    start = temp;
    return start;
}

void addtend(struct node *start,int num){
    struct node *temp, *p;
    if(start==NULL){
        printf("nilai kosong");
        return;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info=num;
    p=start;
    while(p->link!=NULL){
        p = p->link;
    }
    p->link = temp;
    temp->link = NULL;
}

struct node *del(struct node *start, int num){
    struct node *temp, *p;
    if(start==NULL){
        printf("Tidak ada isi");
        return start;
    }
    if(start->info==num){
        temp=start;
        start=start->link;
        free(temp);
        return start;
    }
     p=start;
     while(p->link!=NULL){
        if(p->link->info){
            temp = p->link;
            p->link = temp ->link;
            free(temp);
            return start;
        }
        p=p->link;
     }
}

void addafter(struct node *start,int num, int num2){
    struct node *temp, *p;
    p =start;
    while(p!=NULL){
        if(p->info==num2){
            temp=(struct node*)malloc(sizeof(struct node));
            temp->info=num;
            temp->link = p ->link;
            p->link = temp;
            return;
        }
        p=p->link;
    }
    printf("tidak ada isi",num2);
}

struct node *addbefore(struct node *start,int num, int num2){
    struct node *temp, *p;

    if(start->info==num2){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=num;
    temp->link = start;
    start = temp;
    return start;}

    p=start;
    while(p->link!=NULL){
        if(p->link->info==num2){
            temp=(struct node*)malloc(sizeof(struct node));
            temp->info=num;
            temp->link = p->link;
            p->link = temp;
            return start;
        }
        p=p->link;
    }
    printf("tidak ada",num2);
    return start;
}
