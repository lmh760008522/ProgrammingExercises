//����
//���ڸ���N������0<N<1000��������Ҫ����д��һ�������ҳ���N�����е���������������͡�
//����
//��һ�и�������M(0<M<10)����������������
//ÿ��������ݵ�һ�и���N���������������ݵ�������
//��������N����ΪҪ���Ե����ݣ�ÿ����С��1000
//���
//ÿ��������ݽ��ռһ�У���������Ĳ������ݵ�����������


//��������1 ,2������ 
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
				break;//������������i<n 
			}
			if(i==a){//�������� 
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
