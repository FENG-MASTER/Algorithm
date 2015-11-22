#include <stdio.h>
#include <stdlib.h>
void sortAll(int arr[],int n,int k);
int main(void)
{

    int n=0;
    printf("输出n:");
    scanf("%d",&n);

    int* arr=malloc(sizeof(int)*n);
    for(int i =0;i<n;i++){
        arr[i]=i+1;
        printf("%d",i+1);
    }


    sortAll(arr,n,0);
    return 0;
}





void sortAll(int arr[],int n,int k){
    if(k==n-1){
            for(int i =0;i<n;i++){
                printf("%d",arr[i]);
            }
            printf("\n");


    }else{

        for(int i=k;i<n;i++){

                int temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
        sortAll(arr,n,k+1);

        temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;

        }


    }










}
