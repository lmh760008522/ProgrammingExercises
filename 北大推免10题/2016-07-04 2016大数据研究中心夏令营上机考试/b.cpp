#include<cstdio>
#include<cstring> 
int p1,p2,p3;
char s[100];

int main(){
	scanf("%d %d %d\n",&p1,&p2,&p3);
	char ans[1000];
	gets(s);
	int j=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			if(s[i+1]<=s[i-1]){
				ans[j++]=s[i];
			}else if(s[i+1]==s[i-1]+1){
				continue;
			}else{
				if(p3==1){
					for(int k=s[i-1]+1;k<s[i+1];k++){
						for(int s=0;s<p2;s++){
							if(p1==3){
								ans[j++]='*';
							}else{
								if(k>='0' && k<='9'){
									ans[j++]=k;
								}else if(k>='a' && k<='z'){
									if(p1==1){
										ans[j++]=k;
									}else{
										ans[j++]=k-32;
									}
								}else if(k>='A' && k<='Z'){
									if(p1==2){
										ans[j++]=k;
									}else{
										ans[j++]=k+32;
									}
								}
							}
						}
					}
				}else{
					for(int k=s[i+1]-1;k>=s[i-1]+1;k--){
						for(int s=0;s<p2;s++){
							if(p1==3){
								ans[j++]='*';
							}else{
								if(k>='0' && k<='9'){
									ans[j++]=k;
								}else if(k>='a' && k<='z'){
									if(p1==1){
										ans[j++]=k;
									}else{
										ans[j++]=k-32;
									}
								}else if(k>='A' && k<='Z'){
									if(p1==2){
										ans[j++]=k;
									}else{
										ans[j++]=k+32;
									}
								}
							}
						}
					}
				}
			}
		}else{
			ans[j++]=s[i];
		}
	}
	ans[j]='\0';
	puts(ans);
	return 0;
}
