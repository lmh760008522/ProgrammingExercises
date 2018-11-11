#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string.h>
using namespace std;

int e[1020][1020];
int dis[1020];
bool vis[1020]={false};
int n,m,k,ds;

void dijkstra(int s){
	memset(vis,false,sizeof(vis));
	fill(dis,dis+1020,9999999);
	for(int i=0;i<n+m;i++){
		int u=-1,minf=99999999;
		for(int j=0;j<m+n;j++){
			if(minf>dis[j] && vis[j]==false){
				u=j;
				minf=dis[j];
			}
			if(u==-1){
				return;
			}
			vis[u]=true;
			for(int v=1;v<=n+m;v++){
				if(vis[v]==false && e[u][v]!=-1){
					if(dis[u]+e[u][v]<dis[v]){
						dis[v]=dis[u]+e[u][v];
					}
				}
			}
		}
	}
}

int main(){
	
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	memset(e,-1,sizeof(e));
	
	for(int i=0;i<k;i++){
		char s[5],d[5];
		int l;
		scanf("%s %s %d",s,d,l);
		
		int source=0;
		if(s[0]>=48 && s[0] <=57){
			for(int i=0;i<strlen(s);i++){
				source*10;
				source+=s[i]-'0';
			}
		}else{
			int source=0;
			for(int i=1;i<strlen(s);i++){
				source*10;
				source+=s[i]-'0';
			}
			source+=n;
		}
		
		int des=0;
		if(d[0]>=48 && d[0] <=57){
			for(int i=0;i<strlen(d);i++){
				des*10;
				des+=d[i]-'0';
			}
		}else{
			int des=0;
			for(int i=1;i<strlen(d);i++){
				des*10;
				des+=d[i]-'0';
			}
			des+=n;
		}
		
		e[source][des]=e[des][source]=l;
	}
	
	double ansdis=-1,ansavg=99999999;
	int ansid=-1;
	
	for(int i=n+1;i<=m+n;i++){
		double mindis=99999999,avg=0;
		dijkstra(i);
		int j;
		for(j=0;j<n;j++){
			avg+=dis[j];
			if(dis[j]>ds){
				break;
			}
			if(mindis>dis[j]){
				mindis=dis[j];		
			}
		}
		if(j==n){
			if(mindis>ansdis){
				ansdis=mindis;
				ansavg=avg/n;
				ansid=i;
			}else if(mindis == ansdis){
				if(avg/n < ansavg){
					ansavg=avg/n;
					ansid=i;
				}else if(avg/n == ansavg){
					ansid=i;
				}
			}
		}
	} 
	
	if(ansavg==-1){
		printf("NO Sollotion\n");
	}else{
		printf("G%d\n",ansid-n);
		printf("%lf %lf",ansavg,ansdis);
	}
	return 0;
} 
