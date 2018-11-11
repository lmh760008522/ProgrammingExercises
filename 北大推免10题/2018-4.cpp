#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	int st,en;
}node;
vector<node> v;
bool cmp(node a,node b){
	return a.en < b.en;
}

int main(){
	int n;
	scanf("%d\n",&n);
	while(n-- >0){
		int a,b;
		scanf("%d %d\n",&a,&b);
		node temp;
		temp.st=a;
		temp.en=b;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	int ans=1;
	for(int i=1;i<v.size();i++){
		if(v[i].st > v[i-1].en){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
