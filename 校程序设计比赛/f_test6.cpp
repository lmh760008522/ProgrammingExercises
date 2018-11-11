#include<stdio.h>
#include<string.h>
#define MAX 100
char a[MAX],b[MAX];//用字符串进行数字的输入 
int x[MAX+10],y[MAX+10],z[MAX*2+10];//积的位数最多是因数位数的两倍 
int main()
{ 
	int len1,len2,i,j;
	while(~scanf("%s %s",a,b))
	{
		len1=strlen(a);
		len2=strlen(b);
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
		for(;i>=0;i--)  //倒序输出 
			printf("%d",z[i]);
		printf("\n");
	}
	return 0;
}
