#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
typedef struct node{
    int data;
    struct node* next;
}ListNode,*ListNodeP;

typedef ListNodeP List,*Listp;


typedef enum Status{range_err,succeed,failt}Status;

Status List_Init(Listp L);

Status List_creat(Listp L,int arr[],int n);


int List_getLength(Listp L);


int List_empty(Listp L);

Status List_clear(Listp L);

Status List_destroy(Listp L);



Status List_Reverse(Listp L);



void List_printf(Listp L);

Status List_remove(Listp L,int pos);
#endif // LIST_H_INCLUDED
