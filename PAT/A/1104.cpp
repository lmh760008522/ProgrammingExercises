#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	double sum=0;
	double x;
	int i=1;
	while(i<=n){
		scanf("%lf",&x);
		sum+=i*(n+1-i)*x;
		i++;	
	}
	printf("%.2lf",sum);
	return 0;
} 

/* 
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double a[100001];
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum = sum + a[i] * i * (n - i + 1);
    }
    printf("%.2f", sum);
    return 0;
}
*/ 
