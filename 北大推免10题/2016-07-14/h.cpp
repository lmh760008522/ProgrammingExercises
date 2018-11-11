#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;

typedef struct node{
	int id,l,r;
	int parent;
}node;
vector<node> v;

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; i++){
		int n,m;
		scanf("%d %d",&n,&m);
		v.clear();
		v.resize(n+1);
		for(int j=0;j<v.size();j++){
			node temp;
			temp.l=temp.id=temp.r=temp.parent=0;
			v[j]=temp;
		}
		for(int j=0;j<n;j++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			v[x].id=x;
			v[x].l=y;
			v[x].r=z;
			v[y].parent=x;
			v[z].parent=x;
		}
		
		for(int j=0;j<m;j++){
			int type;
			scanf("%d",&type);
			if(type==1){
				int x,y;
				scanf("%d %d",&x,&y);
				if(v[x].parent!=v[y].parent){
					if( v[ v[x].parent ].l == x){
						v[ v[x].parent ].l =y;
					}else{
						v[ v[x].parent ].r =y;
					}
					if( v[ v[y].parent ].l == y){
						v[ v[y].parent ].l =x;
					}else{
						v[ v[y].parent ].r =x;
					}
					swap(v[x].parent,v[y].parent);
				}else{
					swap(v[ v[x].parent ].l,v[ v[x].parent ].r);
				}
			}else{
				int x;
				scanf("%d",&x);
				while(v[x].l !=-1){
					x=v[x].l;
				}
				printf("%d\n",x);
			}
		}
	}
	return 0;
}
