#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

int main(){
	char s[20];
	int dp[20];
	set<char> se;
	gets(s);
	int st=0,len=1,maxlen=0;
	se.insert(s[0]);
	for(int i=1;i<strlen(s);i++){
		if(se.find(s[i]) != se.end()){
			if(len>maxlen){
				maxlen=len;
			}
			se.erase(s[st]);
			st++;
			i--;
			len=0;
		}else{
			len++;
			se.insert(s[i]);
		}
	}
	printf("%d\n",maxlen);
	return 0;
} 
