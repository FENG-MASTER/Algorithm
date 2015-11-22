#include<iostream>
using namespace std;

void shell(int *work,int n)
{
	int i,j,x,d;
	d= n / 2;
	while (d>=1)
	{
	  for (i=d+1;i<=n;i++)
	  {
	    x=work[i];
	    j=i-d;
	    while ((j>0) && (x<work[j]))
	    {
		    work[j+d]=work[j];
		    j-=d;
	    }
	    work[j+d]=x;
	  }
	  d /= 2;
	}
}
int main(){
    int a[100],b,c,n,i;
    cout<<"请输入需排序的数字个数:";
    cin>>n;
    cout<<"请输入需排序的数字";
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    shell(a,n);
    cout<<"从小到大排序结果为:";
    for (i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
    system("pause");
}
