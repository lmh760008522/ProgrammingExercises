#include<cstdio>
#include<string.h>
using namespace std;

char a[10];
int visit[10];
char ans[10];
int n;

void pailie(int k){
	
	if( k == n){
		puts(ans);
	}
	for(int i=0;i<n;i++){
		if(visit[i]==0){
			visit[i]=1;
			ans[k]=a[i];
			pailie(k+1);
			visit[i]=0;
		}
	}

	return;
}

int main(){
	scanf("%d\n",&n);
	memset(visit,0,sizeof(visit));
	gets(a);
	pailie(0);
	return 0;
}
