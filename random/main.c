#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int randInt(int a,int b){
	b=b+1;
	return ((rand()%(b-a))+a);
}

int review(int *arr,int n ,int num){
	int status=0;
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==num){
			status=1;
			break ;


		}

	}
	return status;

}


void printfArr(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d,",arr[i]);

	}
	printf("\b \n");

}




void rand_type_1(int *arr ,int n){
	int i;
	for(i=0;i<n;i++){
		arr[i]=-1;
	}
	arr[0]=randInt(1,n);
	int j;
	int rand=randInt(1,n);
	for(j=1;j<n;j++){

		while(review(arr,j,rand)==1){
			rand=randInt(1,n);
		}
		arr[j]=rand;

	}


}

void rand_type_2(int *arr ,int n){
	int i;
	for(i=0;i<n;i++){
		arr[i]=-1;
	}

    int *used=(int *)malloc(sizeof(int)*n);
//	int used[n];
	for(i=0;i<n;i++){
		used[i]=0;
	}

	int rand=randInt(1,n);
	used[rand]=1;
	arr[0]=rand;
	int j ;
	for(j=1;j<n;j++){


        while(used[rand]==1){
            rand=randInt(1,n);
        }
        arr[j]=rand;
        used[rand]=1;

	}

}

void swap(int *a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}


void rand_type_3(int *arr ,int n){
	int i;
	for( i=0;i<n;i++){
		//Í³Ò»¸³³õÖµ
		arr[i]=i+1;
	}
	for(i =0;i<n;i++){
		swap(&arr[randInt(0,n-1-i)],&arr[n-1-i]);
	}
}


int main(int argc, char *argv[]) {
    srand((int)time(0));


    int n;
    scanf("%d",&n);

    if(n>0){
        int *arr=(int *)malloc(sizeof(int)*n);
     //   int arr[n];
        rand_type_1(arr,n);
        printfArr(arr,n);
        rand_type_2(arr,n);
        printfArr(arr,n);
        rand_type_3(arr,n);
        printfArr(arr,n);
    }else{
        printf("error");


    }



	return 0;
}
