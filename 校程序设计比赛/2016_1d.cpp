#include <cstdio>
#include<string.h>
long long toNum(char* s){
	long long ans=0;
	for(int i=0;i<strlen(s);i++){
		ans*=10;
		ans+=s[i]-'0';
	}
	return ans;
} 
int main(){
    int T;
    long long ben,end;
    scanf("%d", &T); 
	while(T --){
        char s[20];
        int k;
        scanf("%s %d",s,&k);      
        ben=toNum(s);      
        int count=0;
        while(count++ < k){
        	for(int i=0;i<strlen(s)-1;i++){
        		if(s[i]<s[i+1]){
        			char c=s[i+1];
        			s[i+1]=s[i];
        			s[i]=c;
        			break;
				}
			}
		}
		end=toNum(s);
		printf("%I64d\n",end-ben);
    }
    return 0;
}
