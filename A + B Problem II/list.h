#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
typedef struct node{
    int data;
    struct node* next;
}ListNode,*ListNodeP;

typedef ListNodeP List,*Listp;


typedef enum Status{range_err,succeed,failt}Status;

Status List_Init(Listp L);


Status List_Retrieve(Listp L,int pos,int * data);


Status List_getPostionElem(Listp L,int pos,ListNodeP *ptr);


Status List_Insert(Listp L,int pos,int data);

void List_printf(Listp L);

int List_getLength(Listp L);

#endif // LIST_H_INCLUDED
