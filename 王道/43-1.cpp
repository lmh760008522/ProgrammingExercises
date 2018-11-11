#include<cstdio>
#include<string.h>
#include<stack>
using namespace std;
int main(){
	char s[101];
	char ans[101];
	stack<char> ss;
	gets(s);
	ss.push('0');
	for(int i=0;i<strlen(s);i++){
		printf("%c",s[i]);
		
		if( s[i] == '(' ){
			//printf("?");
			ss.push('(');
			//printf("?");
			ans[i]='$';
			//printf("?");
		}else if(s[i]==')'){
			if( ss.top()!='('){
				ans[i]='?';
			}else{
				ss.pop();
				ans[i]=' ';
				for(int j=i-1;j>=0;j--){//优化，在堆栈里放（的下标 
					if(ans[j]=='$'){
						ans[j]=' ';
						break;
					}
				}
			}
		}else{
			ans[i]=' ';
		}
	}
	printf("\n");
	for(int i=0;i<strlen(s);i++){
		printf("%c",ans[i]);
	}
	while(ss.top()!='0'){
		ss.pop();
	}
	ss.pop();
	return 0;
} 
