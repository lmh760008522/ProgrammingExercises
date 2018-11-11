#include<cstdio>

int judge(int a,int b){
	if(a==0 && b==2){
		return 1;
	}else if(a==0 && b==5){
		return -1;
	}else if(a==2 && b==5){
		return 1;
	}else if(a==2 && b==0){
		return -1;
	}else if(a==5 && b==0){
		return 1;
	}else if(a==5 && b==2){
		return -1;
	}
	return 0;
}

int main(){
	int n,na,nb;
	scanf("%d %d %d",&n,&na,&nb);
	int a[100],b[100];
	for(int i=0;i<na;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<nb;i++){
		scanf("%d",&b[i]);
	}
	int ans_a=0;
	int p=0,q=0;
	for(int i=1;i<=n;i++){
		if(judge(a[p%n],b[q%n])==1){
			ans_a++;
		}
		p++;q++;
	}
	if(ans_a==n/2){
		printf("draw\n");
	}else if(ans_a<n/2){
		printf("A\n");
	}else{
		printf("B\n");
	}
	return 0;
} 
