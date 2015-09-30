#include <stdio.h>
#include <stdlib.h>
void sortAll(int arr[],int n,int k);
int main(void)
{

    int arr[]={1,2,3,4,5,6,7,8,9};
    sortAll(arr,9,0);
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
