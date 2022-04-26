#include <stdio.h>
#include <stdlib.h>

typedef struct node *address;

struct node{
    int isi;
    address next;
};

address buatnode(int nilai){
    address p = (address)malloc(sizeof(struct node));
    p->isi = nilai;
    p->next = NULL;
    return p;
}

address insertfirst(address head,int nilai){
    address new_node = buatnode(nilai);
    new_node->next = head;
    head = new_node;
    return head;
}
void printvalue(address head){
    address n = head;
    printf("Daftar Nilai Linked List : \n");
    while(n != NULL){
        printf("[%d] ",n->isi);
        n = n->next;
    }
    printf("\n");
}
address sorting(address head){
    int swapped;
    address ptr1;
    address lptr = NULL;
    if(head == NULL){
        return;
    }
    do{
        swapped = 0;
        ptr1 = head;
        while(ptr1->next != lptr){
            if(ptr1->isi < ptr1->next->isi){
                swap(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    return head;
}

void swap(address a,address b){
    int temp = a->isi;
    a->isi = b->isi;
    b->isi = temp;
}

address reverse(address head){
    address prev = NULL;
    while(head != NULL){
        address node_next = head->next;
        head->next = prev;
        prev = head;
        head = node_next;
    }
    return prev;
}

int main(){
    int pil,val;
    address head = NULL;
    while(1){
        system("cls");
        printvalue(head);
        printf("Linked List Menu : \n");
        printf("1. Insert First\n");
        printf("2. Sorting Descending\n");
        printf("3. Reverse Node\n");
        printf("0. Exit \n");
        printf("Input your choice = ");
        scanf("%d",&pil);
        switch(pil){
            case 1:{
                printf("Input Value = ");
                scanf("%d",&val);
                head = insertfirst(head,val);
                system("cls");
                break;
            }
            case 2:{
                head = sorting(head);
                system("cls");
                break;
            }
            case 3:{
                head = reverse(head);
                system("cls");
                break;
            }
            case 0:{
                printf("\n");
                printf("Program Single Linked List telah selesai!!!\n");
                printf("Fadhlan S. J. (1203210064)\n");
                exit(1);
            }
            default:{
            printf("Pilihan belum tersedia/tidak ada!!!\n");
            break;
            }

        }
    }
    return 0;
 }
