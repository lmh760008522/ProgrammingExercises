#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int main(){
	int t;
	char s[1005];
	queue<char> q;
	scanf("%d\n",&t);
	
	for(int k=0;k<t;k++){

	gets(s);
	int j=0;
	if(s[j]!='#'){
		printf("%c",s[j]);	
	}
	for(int i=0;i<strlen(s)-1;i++){	
		if(s[i]=='#' && (s[i+1]>=48 && s[i+1]<=57)){
			j=i+1;
			q.push(s[j]);
			//printf(" j---%d",j);
		}
	}
	for(int i=j+1;s[i]!='#';i++){
		q.push(s[i]);
	}
	while( !q.empty() ){
		char c = q.front();
		printf("%c",c);
		q.pop();
	}
	
	}

	return 0;
} 
