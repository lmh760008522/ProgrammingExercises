//����
//��n*n����������1,2,...,n*n,Ҫ��������Ρ�����n=4ʱ����Ϊ��
//10 11 12 1
//9 16 13 2
//8 15 14 3
//7 6 5 4
//����
//ֱ�����뷽�µ�ά������n��ֵ��(n<=100)
//���
//�����������η���
/* 
#include<iostream>
using namespace std;
int main(){
	int n,i,j,k=1;
	cin>>n;
//	7 8 1
//	6 9 2
//	5 4 3
//	
//	10 11 12 1
//	9  16 13 2
//	8  15 14 3
//	7  6  5  4
//	
//	13 14 15 16 1
//	12 23 24 17 2
//	11 22 25 18 3
//	10 21 20 19 4
//	9  8  7  6  5
//	
//	16 17 18 19 20  1
//	15 30 31 32 21  2
//	14 29 36 33 22  3
//	13 28 35 34 23  4
//	12 27 26 25 24  5
//	11 10  9  8  7  6
	
	for(i=1;i<=n;i++){
		k=1;
		for(j=1;j<=n;j++){
			if((j<i&&i<=(n+1)/2)||(j<(n-i)&&i>(n+1)/2)){
				cout<<k;
				k++;
			}
			else if(j>(n-i)||j>i-1){
				cout<<k;
				k--;
			}else{
				cout<<k;
			}
		}
		cout<<endl;
	}
	return 0;
} 

*/ 



//�𰸣�δ����Ĩ�� 
#include<stdio.h>
int main()
{
 	int i,j,k,t,n,s[100][100];
	 while(scanf("%d",&n)!=EOF)
	 {
		  t=1;
			  for(k=0;k<n/2;k++)
			  {
			
				   j=n-1-k;
				   for(i=k;i<n-k;i++)
				   		 s[i][j]=t++;
				   i--;
				   for(j=n-2-k;j>=k;j--)
				   		 s[i][j]=t++;
				   j++;
				   for(i=n-2-k;i>=k;i--)
				   		 s[i][j]=t++;
				   i++;
				   for(j=k+1;j<n-k-1;j++)
				   		 s[i][j]=t++;
			  }
			  if(n%2)s[n/2][n/2]=t;
			  for(i=0;i<n;i++)
			  {
				   for(j=0;j<n;j++)
				   		 printf("%d ",s[i][j]);
				   printf("\n");
			  }
	 }
 return 0;
}
