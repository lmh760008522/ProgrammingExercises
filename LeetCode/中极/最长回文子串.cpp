#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char s[6]="babad";
	//char s[5]="cbbd";
	int ans=0;
	for(int i=1;i<strlen(s)-1;i++){
		
		//ÆæÊý 
		int j=1;
		while(s[i-j]==s[i+j] && i-j>=0 && i+j<strlen(s)){
			j++;
		}
		if(ans<2*(j-1)+1){
			ans=2*(j-1)+1;
		}
		//Å¼ÓÒ 
		if(s[i+1]==s[i]){
			j=1;
			while(s[i-j]==s[i+j+1] && i-j>=0 && i+j+1<strlen(s)){
				j++;
			}
			if(ans<2*j){
				ans=2*j;
			}
		}
		//Å¼×ó 
		if(s[i-1]==s[i]){
			j=1;
			while(s[i-j-1]==s[i+j] && i-j-1>=0 && i+j<strlen(s)){
				j++;
			}
			if(ans<2*j){
				ans=2*j;
			}
		}	
	}
	printf("%d",ans);
	return 0;
}
