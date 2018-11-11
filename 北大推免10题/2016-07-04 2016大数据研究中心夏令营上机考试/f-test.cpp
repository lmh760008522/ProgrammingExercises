#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;

typedef struct node{
	int color;
	vector<int> next;
}node;

vector<node> map;
char s[30];
int c[5];
int visit[5]={0};
int visitn[30]={0};
int ans,n,mi,num;

void dfs(int x){
	num++;
	if(num == n){
		if(mi>ans){
			mi=ans;
		}
		return;
	}	
	memset(c,0,sizeof(c));
	for(int i=0;i<map[x].next.size();i++){
		c[ map[ map[x].next[i] ].color ]=1;
	}
	for(int i=1;i<=4;i++){
		if(c[i]==0){
			map[x].color=i;
			c[i]=1;
			if(i>ans){
				ans=i;
			}
			for(int i=0;i<map[x].next.size();i++){
				if(map[ map[x].next[i]].color ==0){
					visitn[ map[x].next[i] ]=1;
					num++;
					dfs(map[x].next[i]);
				}
			}
		}
	}
	
	return;
}

int main(){
	while( scanf("%d\n",&n)!=EOF){
		if(n==0){
			break;
		}
		map.resize(n);
		memset(visit,0,sizeof(visit));
		memset(visitn,0,sizeof(visitn));
		for(int i=0;i<n;i++){
			gets(s);
			int x=s[0]-65;
			node temp;
			temp.color=0;
			for(int j=2;s[j]!='\0';j++){
				temp.next.push_back(s[j]-65);
			}
			map[x]=temp;
		}
		ans=0,mi=9999,num=0;
		for(int i=0;i<n;i++){
			if(visitn[i]==0){
				dfs(i);
			}
		}
		printf("%d\n",mi);
	}
	return 0;
}
