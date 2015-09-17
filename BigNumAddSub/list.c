
#include<stdio.h>
#include"list.h"




Status List_Init(Listp L)
{
    Status s=failt;
    *L=(ListNodeP)malloc(sizeof(ListNode));
    if(*L){
        (*L)->data=1;
        (*L)->next=NULL;
        s=succeed;
    }
    return s;

}


Status List_Retrieve(Listp L,int pos,int * data){
    Status s=range_err;
    ListNodeP p=(*L)->next;
    int i =1;
    while(p&&i<pos){
        i++;
        p=p->next;
    }

    if(p&&i==pos){
        *data=p->data;
        s=succeed;

    }

    return s;

}


Status List_getPostionElem(Listp L,int pos,ListNodeP *ptr){
    Status s=failt;
    ListNodeP p=*L;
    int i = 0;
    while(p&&i<pos){
        i++;
        p=p->next;
    }
    if(p&&i==pos){
        *ptr=p;
        s=succeed;
    }
    return s;

}


Status List_Insert(Listp L,int pos,int data){
    Status s=failt;
    ListNodeP pre,nodep;
    s=List_getPostionElem(L,pos-1,&pre);
    if(s=succeed){
        ListNodeP nodep = (ListNodeP)malloc(sizeof(ListNode));
        if(nodep){
            nodep->data=data;
            nodep->next=pre->next;
            pre->next=nodep;
        }else{
            s=failt;
        }
    }

}


int List_getLength(Listp L){
    int i = 0;
    ListNodeP p=(*L)->next;
    while(p){
        i++;
        p=p->next;
    }
    return i;
}


int List_empty(Listp L){
    return (List_getLength(L)==0?0:1);
}


Status List_clear(Listp L){
    ListNodeP p=*L,q=p->next;
    while(q){
        p->next=q->next;
        free(q);
        q=p->next;
    }

}

Status List_destroy(Listp L){
    List_clear(L);
    free(*L);

}




Status List_Reverse(Listp L){
    Status status = succeed;
    ListNodeP p = (*L)->next,q,pre;
    List b;
    List_Init(&b);
    pre = b;
    while(p){
        q = (ListNodeP)malloc(sizeof(ListNode));
        if(!q){
            status = failt;
            break;
        }
        q->data = p->data;
        q->next = pre->next;
        pre->next = q;
        p = p->next;
    }
    if(status == succeed){
        List_destroy(L);
        *L = b;
    }
    return status;
}





void List_printf(Listp L){

    if((*L)->data==-1){
        printf("-");

    }
    ListNodeP p=(*L)->next;
    while(p){
        printf("%d",p->data);
        p=p->next;
    }

}


Status List_remove(Listp L,int pos){
    Status s;
    ListNodeP ptr,q;
    s=List_getPostionElem(L,pos-1,&ptr);
    if(s==succeed){
        q=ptr->next;
        ptr->next=q->next;
        free(q);

    }

    return s;


}



