#include<cstido>
#include<queue>
using namespace std;

typedef struct mouse{
	int w;
	int r;
}mice[1010];

int main(){
	int p,g,o;
	scanf("%d %d",&p,&g);
	for(int i=0;i<p;i++){
		scanf("%d",&mice[i].w);
	}
	queue<int> q;
	for(int i=0;i<p;i++){
		scanf("%d",&o);
		q.push(o);
	}
	int temp=p;
	int group;
	while(q.size()!=1){
		if(temp % g==0){
			group=temp/g;
		}else{
			group=temp/g+1;
		}
		for(int i=0;i<g;i++){
			int k=q.front();
			for(int j=0;j<g;j++){
				if(i*g+j>=temp) break;
				int front =q.front();
				if()
			}
		}	
	}
	return 0;
}
