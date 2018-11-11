#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[1000];
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	sort(a,a+n);
	int max=99999;
	for(int i=1; i<n; i++){
		if(a[i]-a[i-1] < max){
			max = a[i] - a[i-1];
		}
	}
	printf("%d", max);
	return 0;
}
