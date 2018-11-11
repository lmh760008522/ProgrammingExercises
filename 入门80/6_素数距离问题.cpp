//描述
//现在给出你一些数，要求你写出一个程序，输出这些整数相邻最近的素数，并输出其相距长度。如果左右有等距离长度素数，则输出左侧的值及相应距离。
//如果输入的整数本身就是素数，则输出该素数本身，距离输出0
//输入
//第一行给出测试数据组数N(0<N<=10000)
//接下来的N行每行有一个整数M(0<M<1000000)，
//输出
//每行输出两个整数 A B.
//其中A表示离相应测试数据最近的素数，B表示其间的距离


#include<iostream>
using namespace std;
#include<stdio.h>
int main(){
	int num,n,len=1,i;
	scanf("%d",&num);
	while(num>0){
		scanf("%d",&n);
		for(i=2;i<n;i++){
			if(n%i==0){
				break;
			}
		}
		if(i==n){//若n为素数 
			printf("%d %d",n,0);
		}else{//若n不为素数 
				for(len=1;len<n-1;len++){//长度不超过此数时 
					for(i=2;i<(n-len);i++){
						if((n-len)%i==0){
							break;
						}
					}
					if(i==(n-len)){//若n为素数 
						printf("%d %d",n-len,len);
						break;//左边有，则输出并结束循环 
					}
					//左边没有看右边 
					for(i=2;i<(n+len);i++){
						if((n+len)%i==0){
							break;
						}
					}
					if(i==(n+len)){//若n为素数 
						printf("%d %d",n+len,len);
						break;
					}
				}
				if(len==n-1){//若在小于n的范围内左右都没找到 ，只有右有 
					while(true){
						for(i=2;i<(n+len);i++){
							if((n+len)%i==0){
								break;
							}
							if(i==(n+len)){//若n为素数 
								printf("%d %d",n+len,len);
								break;
							}
						}
						len++;
					}
				}	
			} 
		num--;
	}
	return 0;
} 

//解题思路：这个题仍然是利用筛法求素数，把所有的素数先求出来放到一个数组中，然后再根据所输入的数利用二分法进行查找。若找到该数，说明该数是素数，输出该数，查找结束；若循环结束还没有找到，则根据当前的a[low]、a[end]与输入的数进行计算比较，哪个满足条件输出哪个。
/*
来自网络，具体代码：
#include <stdio.h>
int a[1000010]={0};
int main()
{
	int i,j,len=0;
	//筛法求素数
	for(i=2;i<1000010;i++)
		if(a[i]==0)
			for(j=i+i;j<1000010;j=j+i)
				a[j]=1;//下标不是素数的进行标记
	for(j=2;j<1000010;j++)
		if(a[j]==0)
		{
			a[len]=j;//将下标是素数的依次放入数组中 
			len++;//素数的个数 
		}		
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,low=0,end=len-1,mid;
		scanf("%d",&n);
		while(low<=end)//二分查找
		{
			mid=(low+end)/2;
			if(a[mid]==n)
			{ 
				printf("%d 0\n",a[mid]);//找到了说明是素数，直接输出 
				break;
			}
			else if(a[mid]<n)
				low=mid+1;
			else
				end=mid-1;
		}
		if(low>end)
		{
			if(n==1)
				printf("2 1\n");
			else if(a[low]-n>=n-a[end])
				printf("%d %d\n",a[end],n-a[end]);
			else if(a[low]-n<n-a[end])
				printf("%d %d\n",a[low],a[low]-n);
		}
	}
	return 0;
}
*/


/*优秀代码
 
#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n)
{
	for(int k=2;k<=sqrt((double)n);k++)
		if((n%k)==0)
			return false;
	return true;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num,i,j;		
		cin>>num;
		if(num==1)
		{
			cout<<"2 1"<<endl;
			continue;
		}
		for(i=num;!isprime(i);i--);	
		for(j=num;!isprime(j);j++);	
		
		if((num-i)<(j-num))
			cout<<i<<' '<<(num-i)<<endl;
		else if((num-i)>(j-num))
			cout<<j<<' '<<(j-num)<<endl;
		else if((num-i)==(j-num))
			cout<<i<<' '<<(num-i)<<endl;
	}
}         
*/ 
//我觉得：先定义数组，是素数则为1，否则为0；然后查表，计算左右距离，比较输出

