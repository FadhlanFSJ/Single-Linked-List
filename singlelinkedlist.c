#include <stdio.h>
#include <stdlib.h>

typedef struct node *address;

struct node{
    int isi;
    address next;
};

address createNode(int nilai){
    address p;
    p = (address)malloc(sizeof(struct node));
    p->isi = nilai;
    p->next = NULL;
    return(p);
}
address insertfirst(address head,int nilai){
    address new_node = createNode(nilai);
    new_node->next = head;
    head = new_node;
    return(head);
}
address insertlast(address head,int nilai){
    address tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    address new_node = createNode(nilai);
    tail->next = new_node;

    return(head);
}
address insertafter(address head,int nilai,int prev_nilai){
    address cursor = head;
    while(cursor->isi!= prev_nilai){
        cursor = cursor->next;
    }
    address new_node = createNode(nilai);
    new_node->next = cursor->next;
    cursor->next = new_node;
    return(head);
}
address insertbefore(address head,int nilai,int next_nilai){
    if(head->isi == next_nilai){
        head = insertfirst(head,nilai);
    }else{
        address cursor,prevcursor;
        cursor = head;
        do{
            prevcursor = cursor;
            cursor = cursor->next;
        }while(cursor->isi != next_nilai);

        address new_node = createNode(nilai);
        new_node->next = cursor;
        prevcursor->next = new_node;
    }return(head);

}
address deletefirst(address head){
    if(head == NULL){
        return;
    }
    address first = head;
    head = head->next;
    first->next = NULL;
    free(first);
    return(head);
}
address deletelast(address head){
    if(head==NULL){
        return;
    }
    address tail = head;
    address prevtail = NULL;
    while(tail->next!=NULL){
        prevtail=tail;
        tail = tail->next;
    }
    prevtail->next = NULL;
    free(tail);
    return(head);
}
address deleteafter(address head,int nilai){
    address cursor = head;
    while (cursor!=NULL){
        if(cursor->next->isi == nilai){
           break;
           }cursor = cursor->next;
    }
    if(cursor != NULL){
        address temp = cursor->next;
        cursor->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    return(head);
}
void tampilnilai (address head){
    address n = head;
    printf("Daftar Nilai Linked List : \n");
    while (n != NULL){
        printf("[%d] ",n->isi);
        n = n->next;
    };
    printf("\n");
}
address count (address head){
    int count = 0;
    struct node *p;
    p = head;
    while(head != NULL){
        count++;
        head=head->next;
    }
    printf("Jumlah Node Sekarang : %d\n",count);
    return(head);
}
address dispose (address head){
    struct node *temp;
    if(head == NULL){
        return;
    }
    while(head != NULL){
        head = NULL;
    }
    printf("Semua Node telah dihapus!!!\n");
    return(head);
}
address bubblesort(address head){
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
    int pil,val,val1;
    address head = NULL;
    while(1){
        system("cls");
        tampilnilai(head);
        printf("--------------------Linked List--------------\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert After\n");
        printf("4. Insert Before\n");
        printf("5. Delete First \n");
        printf("6. Delete Last\n");
        printf("7. Delete After\n");
        printf("8. Hitung jumlah node\n");
        printf("9. Hapus semua Node\n");
        printf("10. Sort Node \n");
        printf("11. Reverse Node\n");
        printf("0. Keluar\n");
        printf("Masukkan Pilihan = ");
        scanf("%d",&pil);
        switch(pil){
            case 1 :{
                printf("Masukkan Nilai = ");
                scanf("%d",&val);
                head = insertfirst(head,val);
                system("cls");
                break;
            }
            case 2 :{
                printf("Masukkan Nilai = ");
                scanf("%d",&val);
                head = insertlast(head,val);
                system("cls");
                break;
            }
            case 3 :{
                printf("Masukkan Nilai = ");scanf("%d",&val);
                printf("Ingin memasukkan nilai setelah = ");scanf("%d",&val1);
                head = insertafter(head,val,val1);
                system("cls");
                break;
            }
            case 4 :{
                printf("Masukkan nilai = ");scanf("%d",&val);
                printf("Ingin memasukkan nilai tersebut sebelum = ");scanf("%d",&val1);
                head = insertbefore(head,val,val1);
                system("cls");
                break;
            }
            case 5:{
                head = deletefirst(head);
                system("cls");
                break;
            }
            case 6:{
                head = deletelast(head);
                system("cls");
                break;
            }
            case 7:{
                printf("Masukkan nilai yang ingin dihapus = ");
                scanf("%d",&val);
                head = deleteafter(head,val);
                break;
            }
            case 8:{
                head = count(head);
                system("pause");
                break;
            }
            case 9:{
                head = dispose(head);
                system("pause");
                break;
            }
            case 10:{
                head = bubblesort(head);
                system("pause");
                break;
            }
            case 11:{
                head = reverse(head);
                system("pause");
                break;
            case 0:{
                printf("\n");
                printf("Program Single Linked List telah selesai!!!\n");
                printf("Fadhlan S. J. (1203210064)\n");
                exit(1);
            }
            default :{
                printf("Pilihan belum tersedia");
                break;
            }
        }
    }


    return 0;
}
