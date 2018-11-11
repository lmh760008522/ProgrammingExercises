//输入
//第一行：T 表示有T组测试数据
//每组测试数据第一行：N 表示定单数
//每组测试数据接下来有N行，每行有三个整数 A B C 表示房间数，开始住宿时间和天数
//1<=T<=100
//1<=N<=10000 1<=A<=10 1<=B<=180 1<=c<=10
//输出
//输出一个整数，为满足所有定单要求的最少房间数。

//超时？？ 
#include<stdio.h>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
	int T,n,min=0,i,j,k;
	cin>>T;
	while(T>0){//测试数据 
		int F[10000][3]={0};
		cin>>n;
		i=0;
		while(i<n){//订单数 
			scanf("%d %d %d",&F[i][0],&F[i][1],&F[i][2]);
			F[i][2]+=F[i][1];//最大天数 
			i++;
		}
		//排序
		for(i=0;i<n;i++) {
			for(j=0;j<(n-i-1);j++){
				if(F[j][1]>F[j+1][1]){
					k=F[j][0];
					F[j][0]=F[j+1][0];
					F[j+1][0]=k;
					k=F[j][1];
					F[j][1]=F[j+1][1];
					F[j+1][1]=k;
					k=F[j][2];
					F[j][2]=F[j+1][2];
					F[j+1][2]=k;
				}
			} 
		}
		min=F[0][0];
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(F[i][1]>=F[j][2]){
					F[i][0]-=F[j][0];
					if(F[i][0]>0){
						continue;
					}else{
						F[i][0]=0;
						break;
					}
				}	
			}
			min+=F[i][0];
		}
		cout<<min<<endl;
		T--;
	}
	return 0; 
} 

//答案1
/* 
#include <iostream>
#include <algorithm>    
using namespace std; 
int main(){
 int n;
 cin >> n;
 while(n--){
  int m,rm,st,sy,a[10001]={0};
  cin >> m;
  while(m--){
   cin>>rm>>st>>sy;
   for(int i=st;i<st+sy;i++) 
		a[i]+=rm; 
  }                      
  cout<< *max_element(a,a + 1001)<<endl;
  }
  return 0;
  }  
  */ 
  
  //答案2
  /* 
  #include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a,b,c,i;//房间数，开始住宿，住宿天数
		int d[200];
		for(i=0;i<199;i++)
		{
			d[i]=0;
		}
		int max=d[0];
		while(n--)
		{
			cin>>a>>b>>c;
			for(i=b;i<(b+c);i++)
			{
				d[i]+=a;
			}
		}
		for(i=1;i<199;i++)
		{
			if(d[i]>max)
				max=d[i];
		}
		cout<<max<<endl;
	}
	return 0;
} 
*/ 
