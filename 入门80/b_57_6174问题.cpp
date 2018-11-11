//描述
//假设你有一个各位数字互不相同的四位数，把所有的数字从大到小排序后得到a,从小到大后得到b,然后用a-b替换原来这个数，并且继续操作。例如，从1234出发，依次可以得到4321-1234=3087、8730-378=8352、8532-2358=6174，又回到了它自己！现在要你写一个程序来判断一个四位数经过多少次这样的操作能出现循环，并且求出操作的次数
//
//比如输入1234执行顺序是1234->3087->8352->6174->6174,输出是4
//
//输入
//第一行输入n,代表有n组测试数据。
//接下来n行每行都写一个各位数字互不相同的四位数
//输出
//经过多少次上面描述的操作才能出现循环


//timelimited
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,count=1,que[4],t,max,min,a,b,i,j;
	cin>>n;
	while(n>0){
		cin>>b;
		while(true){
			for(i=0;i<4;i++){
				que[i]=(b%int((pow(10,4-i))))/(pow(10,3-i));
			}
			//从大到小排序 ///#include<algorithm> sort(a,a+4) 
	 		for(i=0;i<3;i++){
	 			for(j=0;j<4-i;j++){
	 				if(que[j]<que[j+1]){
	 					t=que[j];
				 		que[j]=que[j+1];
				 		que[j+1]=t;
					 }
				 }
			 } 
			 max=1000*que[0]+100*que[1]+10*que[2]+que[3];
			 min=1000*que[3]+100*que[2]+10*que[1]+que[0];
			 a=max-min;
			 if(a==b){
			 	cout<<(count-1)<<endl;
				break;
			 }else{
			 	b=a;
				count++;
			}
			//	cout<<max<<' '<<min<<' '<<a<<' '<<(count-1)<<endl; 
		}
		n--;
	} 
	return 0;
} 

 
//#include<iostream>
//#include<algorithm>
//#include<stdio.h>
//using namespace std;
//int main()
//{
//	//freopen("1.txt","r",stdin);
//	int k;
//	cin>>k;
//	while(k--)
//	{
//		int n,a[4],n1,n2;
//		scanf("%d",&n);
//		int s=1;
//		while(n!=6174)										///注意找规律 
//		{
//			a[0]=n%10;
//			a[3]=n/1000;
//			a[1]=n/10%10;
//			a[2]=n/100%10;
//			sort(a,a+4);
//			n1=1000*a[3]+100*a[2]+10*a[1]+a[0];
//			n2=1000*a[0]+100*a[1]+10*a[2]+a[3];
//			n=n1-n2;										///注意变量替换 
//			s++;
//		}
//		printf("%d\n",s);
//	}
//}        
