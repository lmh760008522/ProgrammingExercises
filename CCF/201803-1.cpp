#include<stdio.h>
int main(){
	int ans=0;
	int len=0;//连续长度 
	int a;
	scanf("%d",&a);
	while(a!=0){
		if(a==1){
			ans++;
			len=0;
		}else if(a==2){
			len++;
			ans+=2*len;
		}
		scanf("%d",&a);
	} 
	printf("%d",ans);
	return 0;
} 
