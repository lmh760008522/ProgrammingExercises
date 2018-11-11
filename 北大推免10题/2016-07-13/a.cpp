#include<cstdio>
int main(){
	int k;
	scanf("%d",&k);
	int ans1=0,ans5=0,ans10=0;
	for(int i=0;i<k;i++){
		int num;
		scanf("%d",&num);
		if(num==1){
			ans1++;
		}else if(num==5){
			ans5++;
		}else if(num==10){
			ans10++;
		}
	} 
	printf("%d\n%d\n%d\n",ans1,ans5,ans10);
	return 0;
} 
