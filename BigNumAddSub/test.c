#include<stdio.h>
#include"list.h"

void test(){
    /*
    测试链表函数

    测试结果:全部函数运行通过


    */

    List A;
    int a[]={1,2,3,4};
    List B;
    int b[]={5,6,7,8,9};
    List_Init(&A);
    List_Init(&B);
    List_creat(&A,a,4);
    List_creat(&B,b,5);
    printf("\nA:");
    List_printf(&A);
    printf("\nB:");
    List_printf(&B);
    List_Insert(&A,1,2);
    printf("\nA:");
    List_printf(&A);
    printf("\nA length:%d",List_getLength(&A));
    List_clear(&B);
    printf("\nB:");
    List_printf(&B);
    List_destroy(&B);



}
