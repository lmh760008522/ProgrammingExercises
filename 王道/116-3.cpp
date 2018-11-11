#include<cstdio>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct node{
	int l,r;
	int edge;
	int state;
}node;

int city[105];
vector<node> rode;

bool cmp(node a,node b){
	return a.edge<b.edge;
}

int findroot(int x){
	if(city[x]==-1){
		return x;
	}else{
		int temp=findroot(city[x]);
		city[x]=temp;
		return temp;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	while(n != 0){
		for(int i=0;i<=n;i++){
			city[i]=-1;
		}
		for(int i=1;i<=n*(n-1)/2 ;i++){
			int a,b,l,s;
			scanf("%d %d %d %d",&a,&b,&l,&s);
			node d;
			d.l=a;
			d.r=b;
			d.edge=l;
			d.state=s;
			if(s==1){
				city[a]=b;
			}
			rode.push_back(d);
		}
		sort(rode.begin(),rode.end(),cmp);
		
		int ans=0;
		for(int i=0;i<rode.size();i++){
			if( findroot( rode[i].l) != findroot(rode[i].r)  ){
				city[ rode[i].l]=rode[i].r;
				ans+=rode[i].edge;
			}
		}
		printf("%d\n",ans);
		rode.clear();
		scanf("%d",&n);
	}
	
	return 0;
} 
