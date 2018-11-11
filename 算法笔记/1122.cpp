//判断是否是哈密顿图 
#include<cstdio>
int main(){
	int n,m;//结点 边 
	scanf("%d %d",&n,&m);
	int e[201][201]={-1};
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		e[a][b]=e[b][a]=1;
	}
	int k;
	scanf("%d",&k);
	while(k-- >0){
		int n0;
		int cun[200];
		bool visit[201]={false};
		scanf("%d",&n0);
		for(int i=0;i<n0;i++){
			scanf("%d",&cun[i]);
			//printf("?");
		}
		if(n0-1!=n || cun[0]!=cun[n0-1]){
			//printf("%d %d %d NO1\n",n0,cun[0],cun[n0-1]);
			printf("NO1\n");
			continue;
		}
		bool flag=true;
		int i;
		for(i=0;i<n0-1;i++){
			if(visit[cun[i]]==true){
				flag=false;
				break;
			}else{
				visit[cun[i]]=true;
				if(e[cun[i]][cun[i+1]]!=1){
					flag=false;
				}
			}
		}
		if(flag==false){
			printf("NO2\n");
		} else{
			printf("YES\n");
		}
		
	}
	return 0;
}
