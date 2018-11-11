#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int a[1000];
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	bool flag = false;
	int i=0;
	for(int j=1; j<n; i++){
		while(a[i]==a[j]){
			j++;
		}
		if(i == n-j){
			flag = true;
		//	printf("hh");
			break;
		}
	}
	if(flag){
		printf("%d", a[i]);
	}else{
		printf("-1");
	}
	return 0;
}
