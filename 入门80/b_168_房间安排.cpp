//����
//��һ�У�T ��ʾ��T���������
//ÿ��������ݵ�һ�У�N ��ʾ������
//ÿ��������ݽ�������N�У�ÿ������������ A B C ��ʾ����������ʼס��ʱ�������
//1<=T<=100
//1<=N<=10000 1<=A<=10 1<=B<=180 1<=c<=10
//���
//���һ��������Ϊ�������ж���Ҫ������ٷ�������

//��ʱ���� 
#include<stdio.h>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
	int T,n,min=0,i,j,k;
	cin>>T;
	while(T>0){//�������� 
		int F[10000][3]={0};
		cin>>n;
		i=0;
		while(i<n){//������ 
			scanf("%d %d %d",&F[i][0],&F[i][1],&F[i][2]);
			F[i][2]+=F[i][1];//������� 
			i++;
		}
		//����
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

//��1
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
  
  //��2
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
		int a,b,c,i;//����������ʼס�ޣ�ס������
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
