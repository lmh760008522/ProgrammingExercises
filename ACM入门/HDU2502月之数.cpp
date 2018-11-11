#include<stdio.h>
#include<math.h>

int a[21];

void zb(){
	a[0] = 0;
	a[1] = 1;
	a[2] = 3;
	int sum = a[0] + a[1] + a[2];
	for(int i =3; i<21; i++){
		a[i] = sum + pow(2,i-1);
		sum +=a[i];
	}
}

int main(){
	int t;
	scanf("%d", &t);
	zb();
	for(int i=0; i<t;i++){
		int n;
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}
	return 0;
} 
