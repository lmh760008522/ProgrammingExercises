//描述
//现在给你N个数（0<N<1000），现在要求你写出一个程序，找出这N个数中的所有素数，并求和。
//输入
//第一行给出整数M(0<M<10)代表多少组测试数据
//每组测试数据第一行给你N，代表该组测试数据的数量。
//接下来的N个数为要测试的数据，每个数小于1000
//输出
//每组测试数据结果占一行，输出给出的测试数据的所有素数和


//素数大于1 ,2是素数 
#include<iostream>
using namespace std;

int main(){
	int num,n,a,i,sum;
	cin>>num;
	while(num>0){
		cin>>n;
		sum=0;
		while(n>0){
			cin>>a;	
			for(i=2;i<a;i++){
				if(a%i==0)
				break;//若不是素数，i<n 
			}
			if(i==a){//若是素数 
				sum+=a;
			}
			n--;
		}
		cout<<sum<<endl;
		num--;
	}
	return 0;
} 





 /*
#include<stdio.h>
#include <math.h>
int main()
{
	int m,n,i,j,a[1000],flag=0;
	long s;
	scanf("%d",&m);
	while(m--)
	{
		s=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			if(a[i]==1)	continue;
			flag=0;
			for(j=2;j<=sqrt(a[i]);j++)
			{
				if(a[i]%j==0)
				{flag=1;break;}			
			}
			if(flag==0)	s+=a[i];
		}
	printf("%d\n",s);
	}
	return 0;
}        
*/
