#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define MAX 10000

int* chengfa(string a,string b){	
	//char a[MAX],b[MAX];//���ַ����������ֵ����� 
	int x[MAX+10],y[MAX+10],z[MAX*2+10];//����λ�����������λ�������� 
	int len1,len2,i,j;
	len1=a.length();
		len2=b.length();
		for(j=0,i=len1-1;i>=0;i--)//���ַ������ַ�ת��Ϊ���֣������򴢴� 
			x[j++]=a[i]-'0';
		for(j=0,i=len2-1;i>=0;i--)
			y[j++]=b[i]-'0';
		for(i=0;i<len1;i++)//����������λ�ϵ���������һ������λ�ϵ�������� 
		{
			for(j=0;j<len2;j++)
				z[i+j]=z[i+j]+x[i]*y[j];//�ȳ�����������ͳһ���н�λ 
		}
		for(i=0;i<MAX*2;i++)//���н�λ 
		{
			if(z[i]>=10)  //��>=10 
			{
				z[i+1]=z[i+1]+z[i]/10;  //��ʮλ�����ֽ�λ 
				z[i]=z[i]%10;  //����λ�ϵ���������
			}
		}
		for(i=MAX*2;i>0;i--)  //ɾ��0��ǰ׺ 
		{
			if(z[i]==0)
				continue;
			else
				break;
		}
		return z;
}

int main(){
	long long int a;
	string ans[MAX]="1";
	long long int copy,boby;
	cin>>a;
	copy=a;
	boby=a/2;
	while(copy>2){
		ans=chengfa(ans,to_string( (copy*(copy-1)/2)/boby ));
		//ans*=((copy*(copy-1)/2)/boby)%MOD;
		copy-=2;
		boby--;
	}
	cout<<ans<<endl;
	return 0;
}
