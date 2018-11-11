/*
aa ad
aada

B15080414 任柏翰 2018/4/15 22:29:18
你把aa给第一个

B15080414 任柏翰 2018/4/15 22:29:22
ad 就错了

*/ 

#include<cstdio>
#include <string.h>
int main(){
	int t;
	int i,j;
	char z[1001],g[1001],s[1001];
	int visit[1001];
	scanf("%d\n",&t);
	while(t-- >0){
		gets(z);
		gets(g);
		gets(s);
		memset(visit,0,sizeof(visit));
		j=0;
		for(i=0;i<strlen(s);i++){
			if(s[i]==z[j]){
				j++;
				visit[i]=1;
				if(j==strlen(z)){
					break;
				}
			}
		}
		/*
		for(i=0;i<strlen(s);i++){
			printf("%d ",visit[i]);
		}
		*/
		for(i=0,j=0;i<strlen(s) ;i++,j++){
			if(s[i]!=z[j] && visit[i]==0){
				break;
			}
		}
		//printf("%d",j);
		if(j!=strlen(g)){
			printf("Oh,i want memeda!");
		}else{
			printf("YES,memeda!");
		}
		
	}
	return 0;
}
