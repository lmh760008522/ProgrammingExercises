#include <stdio.h>
int main()
{
	int a[20001];//����ÿһλ���õ����� 
	int temp,digit,n,i,j=0;//tempÿ�εĵ���   digitÿ�ε�����λ��  
	scanf("%d",&n);
	a[0]=1;//��1��ʼ�� 
	digit=1;//λ���ӵ�һλ��ʼ 
	for(i=2;i<=n;i++)
	{
		int num=0;
		for(j=0;j<digit;j++) 
		{
			temp=a[j]*i+num;//��һ������ÿһλ�����ֱ����i�� 
			a[j]=temp%10;//��һ������ÿһλ������������д���
			num=temp/10;
		}
		while(num)//�ж��˳�ѭ����num��ֵ�Ƿ�Ϊ0 
		{
			a[digit]=num%10;//�������� 
			num=num/10;
			digit++;
		}
	}
	for(i=digit-1;i>=0;i--)//�������ÿһλ 
		printf("%d",a[i]);
	printf("\n");
	return 0;
}
