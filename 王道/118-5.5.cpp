#include<cstdio>
int main(){
	int n,m;
	int e[105][105];
	int visit[105];
	scanf("%d %d",&n,&m);
	while(! ( n==0 && m==0)){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[i][j]=-1;
			}
			e[i][i]=0;
		}
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			e[a][b]=e[b][a]=c;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(e[i][k]==-1 || e[k][j]==-1){
						continue;
					}
					if(e[i][j]==-1 || e[i][k]+e[k][j]<e[i][j]){
						e[i][j]=e[i][k]+e[k][j];
					}
				}
			}
		}
		printf("%d\n",e[1][n]);
		
		scanf("%d %d",&n,&m);
	}
	return 0;
}
