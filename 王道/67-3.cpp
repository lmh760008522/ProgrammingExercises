#include<cstdio>
#include<cstring>
int main(){
	char str[10000];
	while(scanf("%s",str)!=EOF){
		if(strcmp(str,"0")==0){
			break;
		} 
		int ans=10;
		while(ans>=10){
			ans=0;
			for(int i=0; str[i]!=0 ;i++){
				ans+=str[i]-'0';
			}
			sprintf(str,"%d",ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
