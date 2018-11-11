#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t-- >0){
		priority_queue<int,vector<int> , greater<int> > qq;
		int n;
		scanf("%d",&n);
		while(n-- >0){
			int type;
			scanf("%d",&type);
			if(type ==1){
				int u;
				scanf("%d",&u);
				qq.push(u);
			}else if(type ==2){
				int temp=qq.top();
				qq.pop();
				printf("%d\n",temp);
			}
		}
	}
	return 0;
}
