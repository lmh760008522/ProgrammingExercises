#include<cstdio>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct node{
	int l,r;
	int edge;
}node;

bool cmp(node a,node b){
	return a.edge<b.edge;
}



int main(){
	int n;
	vector<node> rode;
	int city[105];
	scanf("%d",&n);
	while(n != 0){
		memset(city,0,sizeof(city));
		for(int i=1;i<=n*(n-1)/2 ;i++){
			int a,b,l;
			scanf("%d %d %d",&a,&b,&l);
			node d;
			d.l=a;
			d.r=b;
			d.edge=l;
			rode.push_back(d);
		}
		sort(rode.begin(),rode.end(),cmp);
		int ans=0;
		for(int i=0;i<rode.size();i++){
			if(city[rode[i].l ]==0 || city[rode[i].r ]==0){
				city[rode[i].l ]=1;
				city[rode[i].r ]=1;
				ans+=rode[i].edge;
			}
		}
		printf("%d\n",ans);
		rode.clear();
		scanf("%d",&n);
	}
	
	return 0;
} 
