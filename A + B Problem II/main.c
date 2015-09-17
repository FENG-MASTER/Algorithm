#include <stdio.h>
#include <stdlib.h>
#include "list.h"



int isNum(char ch);
Listp addTwoBigNum(Listp A,Listp B);

int main(void)
{

    int n=0;
    scanf("%d",&n);

    List* nList1=(List*)malloc(sizeof(List)*n);
    List nList2=(List*)malloc(sizeof(List)*n);
    Listp result=(Listp*)malloc(sizeof(Listp)*n);
     for(int i = 0;i<n;i++){
         //   List A;
            List_Init(&nList1[i]);
        //    List B;
            List_Init(&nList2[i]);
            getchar();
            int num = getchar();
            while(isNum(num)==1){
                List_Insert(&nList1[i],1,num-48);
                num=getchar();

            }

            num=getchar();
            while(isNum(num)==1){
                List_Insert(&nList2[i],1,num-48);
                num=getchar();

            }


            result[i] =addTwoBigNum(&nList1[i],&nList2[i]);




        }


        for(int i=0;i<n;i++){
            printf("\nCase %d:\n",i+1);
            List_printf(&nList1[i]);
            printf(" + ");
            List_printf(&nList2[i]);
             printf(" = ");
             List_printf(result[i]);
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




Listp subTwoBigNum(Listp A,Listp B){}
