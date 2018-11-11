//输入有问题，建议用IOSTREAM 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	char a,b;
	int val;
}node;
vector<node> v;
int visit[27]={0};

bool cmp(node a,node b){
	return a.val<b.val;
}
int main(){
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n-1;i++){
		char st;	int k;
		scanf("%c %d ",&st,&k);
		for(int j=0;j<k;j++){
			char des;	int vall;
			scanf("%c %d",&des,&vall);
			node temp;
			temp.a=st;
			temp.b=des;
			temp.val=vall;
			v.push_back(temp);
		}
	}
	sort(v.begin(),v.end(),cmp);
	int ans=0;
	for(int i=0;i<v.size();i++){
		if(visit[v[i].a-'A']==0 || visit[v[i].b-'A']==0 ){
			visit[v[i].a-'A']=1;
			visit[v[i].b-'A']=1;
			ans+=v[i].val;
		}
	}
	printf("%d\n",ans);
	return 0;
}
