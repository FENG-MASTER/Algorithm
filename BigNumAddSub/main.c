#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*

    超大数据加减法运算程序
    coder:wf
    暂不支持负数形式的输入



*/

int isNum(char ch);
Listp addTwoBigNum(Listp A,Listp B);
Listp subTwoBigNum(Listp A,Listp B);
int main(void)
{


    int fun=0;
    printf("超大数据加减法运算,请输入您要进行的运算[+]或者[-]\n");
    fun=getchar();
    if(fun=='+'||fun=='-'){
            List A;
            List B;
            Listp C;
            List_Init(&A);
            List_Init(&B);
            List_Init(&C);
            getchar();
            int num = getchar();
            while(isNum(num)==1){
                List_Insert(&A,1,num-48);
                num=getchar();

            }

            num=getchar();
            while(isNum(num)==1){
                List_Insert(&B,1,num-48);
                num=getchar();

            }

            fun=='+'? (C =addTwoBigNum(&A,&B)): (C =subTwoBigNum(&A,&B));

            List_Reverse(&A);
            List_Reverse(&B);

            List_printf(&A);
            fun=='+'? printf(" + "):printf(" - ");
            List_printf(&B);
             printf(" = ");
            List_printf(C);


    }else{
        printf("您输入的运算符暂不支持");
    }




    return 0;
}


int isNum(char ch){
    if(ch>='0'&&ch<='9'){
        return 1;
    }else{
        return 0;
    }
}



Listp addTwoBigNum(Listp A,Listp B){

    Listp C=(List)malloc(sizeof(List));
    List_Init(C);
    int A_length=List_getLength(A);
    int B_length=List_getLength(B);
    int max_length = A_length>B_length?A_length:B_length;
    int min_length = A_length>B_length?B_length:A_length;
    Listp Large=A_length>B_length?A:B;

    int deta=0;
    int sum=0;
    int add1=0;
    int add2=0;

    for(int i = 1;i<=min_length;i++){
        List_Retrieve(A,i,&add1);
        List_Retrieve(B,i,&add2);
        sum=add1+add2+deta;
        if(sum>=10){
            deta=1;
            sum=sum-10;
        }else{
            deta=0;
        }

        List_Insert(C,1,sum);

    }

    for(int j = min_length+1;j<=max_length;j++){

            if(deta==1){
                int num=0;
                List_Retrieve(Large,j,&num);
                List_Insert(C,1,num+deta);
                deta=0;

            }else{
                int num=0;
                List_Retrieve(Large,j,&num);
                List_Insert(C,1,num);
            }

    }


    if((min_length==max_length)&&(deta==1)){
                List_Insert(C,1,1);

    }


    return C;


}

int compareBigNum(Listp A,Listp B){

    int aLength=List_getLength(A);
    int bLength=List_getLength(B);
    if(aLength>bLength){
       return 1;
    }else if(aLength<bLength){
        return -1;
    }else{
        int a,b,i=aLength;
        List_Retrieve(A,i,&a);
        List_Retrieve(B,i,&b);
        while(a==b){
            if(i==0){
                return 0;
            }
            i--;
            List_Retrieve(A,i,&a);
            List_Retrieve(B,i,&b);
        }

        if(a>b){
            return 1;

        }else if(a<b){
        return -1;

        }

    }




}


void clearZero(Listp L){

    ListNodeP p;
    p=(*L)->next;
    int i =1;
    while(p->data==0){
        List_remove(L,i);
        i++;
        p=p->next;
    }



}





Listp subTwoBigNum(Listp A,Listp B){

    Listp C=(List)malloc(sizeof(List));
    List_Init(C);

    int comp=compareBigNum(A,B);
    if(comp==0){
        List_Insert(C,1,0);
        return C;
    }else if(comp==-1){

        Listp temp;
        temp=B;
        B=A;
        A=temp;
        (*C)->data=-1;
    }
    int A_length=List_getLength(A);
    int B_length=List_getLength(B);
    int max_length = A_length>B_length?A_length:B_length;
    int min_length = A_length>B_length?B_length:A_length;

    int a=0;
    int b=0;
    int sub=0;
    int deta=0;
    for(int i = 1;i<=min_length;i++){
        List_Retrieve(A,i,&a);
        List_Retrieve(B,i,&b);
        sub=a-b-deta;
        if(sub<0){
            deta=1;
            sub=sub+10;
        }else{
            deta=0;
        }

        List_Insert(C,1,sub);

    }

    for(int i = min_length;i<max_length;i++){



        if(deta==1){
            int num=0;
            List_Retrieve(A,i+1,&num);
            List_Insert(C,1,num-deta);
            deta=0;

        }else{

            int num=0;
            List_Retrieve(A,i+1,&num);
            List_Insert(C,1,num);


        }

    }


    clearZero(C);



    return C;





}





