#include<cstdio>
#include<cstring>
int main(){
	int a,b;
	char n[120];
	long ans;
	char ansans[120];
	int cankao[120];
	char can[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	for(int i=48;i<58;i++){
		cankao[i]=i;
	}
	int j=10;
	for(int i=65;i<71;i++,j++){
		cankao[i]=j;
	}
	j=10;
	for(int i=97;i<103;i++,j++){
		cankao[i]=j;
	}
	
	scanf("%d %s %d",&a,n,&b);
	//a->10
	int cheng=1;
	ans=0;
	for(int i=0;i<strlen(n);i++){
		ans+=cheng*( cankao[ n[i] ]);
		cheng*=a;
	}
	printf("%ld ",ans);
	
	//10->b
	j=0;
	do{
		ansans[j]=can[ans%b];
		ans=ans/b;
		j++;
	}while(ans>0);
	for(int i=j-1;i>=0;i--){
		printf("%c",ansans[i]);
	}
	return 0;
}
