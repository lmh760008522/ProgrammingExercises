//����
//���ڸ�����һЩ����Ҫ����д��һ�����������Щ����������������������������೤�ȡ���������еȾ��볤�����������������ֵ����Ӧ���롣
//�����������������������������������������������0
//����
//��һ�и���������������N(0<N<=10000)
//��������N��ÿ����һ������M(0<M<1000000)��
//���
//ÿ������������� A B.
//����A��ʾ����Ӧ�������������������B��ʾ���ľ���


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
		if(i==n){//��nΪ���� 
			printf("%d %d",n,0);
		}else{//��n��Ϊ���� 
				for(len=1;len<n-1;len++){//���Ȳ���������ʱ 
					for(i=2;i<(n-len);i++){
						if((n-len)%i==0){
							break;
						}
					}
					if(i==(n-len)){//��nΪ���� 
						printf("%d %d",n-len,len);
						break;//����У������������ѭ�� 
					}
					//���û�п��ұ� 
					for(i=2;i<(n+len);i++){
						if((n+len)%i==0){
							break;
						}
					}
					if(i==(n+len)){//��nΪ���� 
						printf("%d %d",n+len,len);
						break;
					}
				}
				if(len==n-1){//����С��n�ķ�Χ�����Ҷ�û�ҵ� ��ֻ������ 
					while(true){
						for(i=2;i<(n+len);i++){
							if((n+len)%i==0){
								break;
							}
							if(i==(n+len)){//��nΪ���� 
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

//����˼·���������Ȼ������ɸ���������������е�������������ŵ�һ�������У�Ȼ���ٸ���������������ö��ַ����в��ҡ����ҵ�������˵��������������������������ҽ�������ѭ��������û���ҵ�������ݵ�ǰ��a[low]��a[end]������������м���Ƚϣ��ĸ�������������ĸ���
/*
�������磬������룺
#include <stdio.h>
int a[1000010]={0};
int main()
{
	int i,j,len=0;
	//ɸ��������
	for(i=2;i<1000010;i++)
		if(a[i]==0)
			for(j=i+i;j<1000010;j=j+i)
				a[j]=1;//�±겻�������Ľ��б��
	for(j=2;j<1000010;j++)
		if(a[j]==0)
		{
			a[len]=j;//���±������������η��������� 
			len++;//�����ĸ��� 
		}		
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,low=0,end=len-1,mid;
		scanf("%d",&n);
		while(low<=end)//���ֲ���
		{
			mid=(low+end)/2;
			if(a[mid]==n)
			{ 
				printf("%d 0\n",a[mid]);//�ҵ���˵����������ֱ����� 
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


/*�������
 
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
//�Ҿ��ã��ȶ������飬��������Ϊ1������Ϊ0��Ȼ�����������Ҿ��룬�Ƚ����

