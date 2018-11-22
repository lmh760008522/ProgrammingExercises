#include<stdio.h>
#include<string.h>
int d;
int n;
int ans[10];//×î¶à18Î»
int count[10]={0};

void check(int num){
	if(num == n-1){
		printf("%d%d",d,count[d]);
		for(int i=0;i<10;i++){
			if(count[i]!=0 && i!=d){
				printf("%d%d",i,count[i]);
			}
		}
		return;
	}
	memset(ans,sizeof(ans),0);
	for(int i=0;i<10;i++){
		if(count[i]!=0){
			ans[i] += 1;
			ans[count[i]]++;
		}
	}
	for(int i=0;i<10;i++){
		count[i] = ans[i];
	}
	check(num+1);
}
int main(){
	
	scanf("%d %d", &d, &n);
	count[d]++;
	if(n==1){
		printf("%d",d);
	}else{
		check(1); 
	}
	return 0;
}
