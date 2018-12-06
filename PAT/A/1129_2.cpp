/*
根据物品被用户接受的次数来计算推荐指数 
*/
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef struct node{
	int id;
	int count;
}node;

bool cmp(node a, node b){
	if(a.count == b.count){
		return a.id < b.id;
	}
	return a.count > b.count;
}

int main(){
	int n,k;
	scanf("%d %d", &n, &k);
	int q;
	scanf("%d", &q);
	map<int, int> mp;
	mp[q]++;
	for(int i=1;i<n;i++){
		scanf("%d", &q);
		printf("%d:",q);
		vector<node> v;
		map<int, int>::iterator iter;
		for(iter = mp.begin(); iter!=mp.end();iter++){
			node temp;
			temp.id = iter->first;
			temp.count = iter->second;
			v.push_back(temp);
		}
		sort(v.begin(), v.end(), cmp);
		for(int j=0;j<k && j<i;j++){
			printf(" %d",v[j].id);
		}
		mp[q]++;
		printf("\n");
	}
	return 0;
} 
