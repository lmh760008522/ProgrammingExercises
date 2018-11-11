#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	char a[21],b[21];
	gets(a);
	gets(b);
	int visit[21]={0};
	for(int i=0,j=0;i<strlen(b);i++){
		if(a[j]=='?'){
			visit[i]=1;
			j++;
			continue;
		}else if(a[j]==b[i] && a[j]!='*'){
			visit[i]=1;
			j++;
			continue;
		}else if(a[j]=='*'){
			j++;
		}
	}
	for(int i=0;i<strlen(b);i++){
		printf("%d",visit[i]);
	}
	return 0;
} 
