#include<stdio.h>
#include<string.h>
char a[8][8];
int visit[8][8];
int n,k;
int count;
int lie[8] = {0};

void found(int num, int h){
	if(num == k){
		count++;
	}
	for(int i=h;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j] == '#' && visit[i][j] != 1){
				visit[i][j] = 1;
				lie[j] = 1;
				found(num+1, h+1);
				lie[j] = 0;
				visit[i][j] = 0;
			}
		}
	}
}

int main(){
	
	while( scanf("%d %d\n", &n, &k) != EOF){
		if( n == -1 && k == -1){
			break;
		}
		
		for(int i = 0;i < n; i++){
			for(int j = 0;j < n; j++){
				scanf("%c", &a[i][j]);
			}
			getchar();
		}
		count = 0;
		memset(lie,n,0);
		memset(visit, n*n, 0);
		found(0,0);
		printf("%d\n", count);
	}
	return 0;
}
