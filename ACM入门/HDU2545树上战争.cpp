#include<stdio.h>
#include<vector>
using namespace std;

typedef struct node{
	int father;
	int height;
}node;

int main(){
	int n, m;
	while( scanf("%d %d", &n, &m) != EOF){
		if( n == 0 && m==0 ){
			break;
		}
		
		vector<node> v;
		v.resize(n+1);
		for(int i=1;i<=n;i++){
			v[i].father = -1;
			v[i].height = 0;
		}
		
		for(int i=0; i<n-1;i++){
			int a,b;
			scanf("%d %d", &a, &b);
			v[b].father = a;
			v[b].height = v[a].height+1;
		}
		
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d %d", &x, &y);
			v[x].height <= v[y].height ? printf("lxh\n") : printf("pfz\n");
		}
	}
	return 0;
} 
