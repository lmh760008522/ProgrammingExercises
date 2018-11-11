#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define MAX 10000

int* chengfa(string a,string b){	
	//char a[MAX],b[MAX];//用字符串进行数字的输入 
	int x[MAX+10],y[MAX+10],z[MAX*2+10];//积的位数最多是因数位数的两倍 
	int len1,len2,i,j;
	len1=a.length();
		len2=b.length();
		for(j=0,i=len1-1;i>=0;i--)//将字符串中字符转化为数字，并倒序储存 
			x[j++]=a[i]-'0';
		for(j=0,i=len2-1;i>=0;i--)
			y[j++]=b[i]-'0';
		for(i=0;i<len1;i++)//将因数各个位上的数字与另一个各个位上的数字相乘 
		{
			for(j=0;j<len2;j++)
				z[i+j]=z[i+j]+x[i]*y[j];//先乘起来，后面统一进行进位 
		}
		for(i=0;i<MAX*2;i++)//进行进位 
		{
			if(z[i]>=10)  //若>=10 
			{
				z[i+1]=z[i+1]+z[i]/10;  //将十位上数字进位 
				z[i]=z[i]%10;  //将个位上的数字留下
			}
		}
		for(i=MAX*2;i>0;i--)  //删除0的前缀 
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
