#include <stdio.h>
int main()
{
	int a[20001];//储存每一位所得到的数 
	int temp,digit,n,i,j=0;//temp每次的得数   digit每次得数的位数  
	scanf("%d",&n);
	a[0]=1;//从1开始乘 
	digit=1;//位数从第一位开始 
	for(i=2;i<=n;i++)
	{
		int num=0;
		for(j=0;j<digit;j++) 
		{
			temp=a[j]*i+num;//将一个数的每一位数都分别乘以i， 
			a[j]=temp%10;//将一个数的每一位数利用数组进行储存
			num=temp/10;
		}
		while(num)//判断退出循环后，num的值是否为0 
		{
			a[digit]=num%10;//继续储存 
			num=num/10;
			digit++;
		}
	}
	for(i=digit-1;i>=0;i--)//倒序输出每一位 
		printf("%d",a[i]);
	printf("\n");
	return 0;
}
