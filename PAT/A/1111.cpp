#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int dis[510],time[510],e[510][510],w[510][510],weight[510];
bool visit[510];
const int inf = 99999999;

int main(){
	//初始化 
	fill(dis,dis+510,inf);
	fill(time,time+510,inf);
	fill(weight,weight+510,false);
	fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    //读取数字 
	int n,m;
	scanf("%d %d", &n, &m);
	int a, b, f, len, t;
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d %d", &a, &b, &f, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if(f != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
	} 
	int begin,end;
	scanf("%d %d",&begin,&end);
	
	vector<int> dispath(n), timepath(n);//记录最短路径的前一个结点 
	//fill(dispath,dispath+n,-1);
	//fill(timepath,timepath+n,-1);
	dis[end]=0;
	fill(visit,visit+510,false);
	for(int i=0; i<n; i++){
		int u=-1,minn = inf;
		for(int j=0; j<n; j++){
			if(visit[j]==false && dis[j]<minn){
				u=j;
				minn = dis[j];
			}
		}
		if(u == -1) break;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(visit[v]==false && e[u][v]!=inf){
				if(dis[u]+e[u][v]<dis[v]){
					dis[v]=dis[u]+e[u][v];
					dispath[v] = u;
					weight[v] = weight[u] + w[u][v];
				}else if(dis[u]+e[u][v] == dis[v] && weight[v] > weight[u] + w[u][v]){
					weight[v] = weight[u] + w[u][v];
                    dispath[v] = u;
				}
			}
		}
	}
	
	time[end]=0;
	fill(visit,visit+510,false);
	for(int i=0; i<n; i++){
		int u=-1,minn = inf;
		for(int j=0; j<n; j++){
			if(visit[j]==false && time[j]<minn){
				u=j;
				minn = time[j];
			}
		}
		if(u == -1) break;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(visit[v]==false && w[u][v]!=inf){
				if(time[u]+w[u][v]<time[v]){
					time[v]=time[u]+w[u][v];
					timepath[v] = u;
				//	weight[v] = weight[u] + w[u][v];
				}else if(time[u]+w[u][v] == time[v]){
				//	weight[v] = weight[u] + w[u][v];
                    timepath[v] = u;
				}
			}
		}
	}
	
	int path1[510],path2[510];
	//fill(path1,path1+510,-1);
//	fill(path2,path2+510,-1);
	path1[0]=end;
	int p;
	
	for(int i=end; dispath[i]!=begin; i=dispath[i]){
		path1[p++]=dispath[i];
	}
	path2[0]=end;
	int q;
	
	for(int i=end; timepath[i]!=begin; i=timepath[i]){
		path2[q++]=timepath[i];
	}
	
	bool flag = false;
	int i;
	for(i=0;i<p && i<q;i++){
		if(path1[i]!=path2[i]){
			break;
		}
	}
	if(p==q&&i==p){
		flag = true;
	}
	
	
	printf("Distance = %d",dis[end]);
	if(flag){
		printf("; Time = %d: ",time[end]);
		for(i = q-1;i>=0;i--){
			printf("%d",timepath[i]);
			if(i!=0){
				printf(" -> ");
			}
		}
	}else{
		printf(": ");
		for(i = p-1;i>=0;i--){
			printf("%d",dispath[i]);
			if(i!=0){
				printf(" -> ");
			}
		}
		printf("\nTime = %d: ",time[end]);
		for(i = q-1;i>=0;i--){
			printf("%d",timepath[i]);
			if(i!=0){
				printf(" -> ");
			}
		}
	}
	return 0;
} 
