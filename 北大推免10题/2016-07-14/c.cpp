#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	char name[15];
	int old;
	int id;
}node;
vector<node> v;

bool cmp(node a,node b){
	if( a.old >=60 && b.old >=60){
		if(a.old==b.old){
			return a.id<b.id;
		}
		return a.old>b.old;
	}else if( a.old >=60 && b.old <60 || a.old <60 && b.old >=60){
		return a.old>b.old;
	}else if( a.old <60 && b.old <60){
		return a.id<b.id;
	}
}


int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		node temp;
		scanf("%s %d",&temp.name,&temp.old);
		temp.id=i;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		puts(v[i].name);
	}
	return 0;
}
