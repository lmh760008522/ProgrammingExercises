#include<stdio.h>
int main()
{
	/* code */
	int n;
	scanf("%d", &n);
	n = n/10;
	int count5 = n/5;
	n = n%5;
	int count3 = n/3;
	int count1 = n%3;
	printf("%d\n", count5*7+count3*4+count1);
	return 0;
}
