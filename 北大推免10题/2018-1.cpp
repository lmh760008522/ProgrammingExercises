#include<cstdio>
#include<stdlib.h>
#include<cstring>
int main(){
	int k;
	scanf("%d",&k);
	int ans=0;
	while(k-- >0){
		char n[20];
		int s=0;
		scanf("%s",n);
		int i,j;
		for(i=0,j=strlen(n)-1; i<=j ;i++,j--){
			if(n[i]!=n[j]){
				break;
			}else{
				if(i!=j){
					s+=n[i]-'0';
					s+=n[j]-'0';
					//printf("s:%d\n",s);
				}else{
					s+=n[i]-'0';
					//printf("s:%d\n",s);
				}
			}
		}
		if(i<=j){
			continue;
		}else{
			//printf("s:%d\n",s);
			char temp[20];
			itoa(s,temp,10);
			int i,j;
			for(i=0,j=strlen(temp)-1; i<=j ;i++,j--){
				if(temp[i]!=temp[j]){
					break;
				}
			}
			if(i<=j){
				continue;
			}else{
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} 
