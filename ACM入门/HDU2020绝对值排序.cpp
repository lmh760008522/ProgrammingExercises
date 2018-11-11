#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

typedef struct node{
	int value;
}node;

bool cmp(node a, node b){
	if(abs(a.value) > abs(b.value)){
		return true;
	}
	return false;
}

int main(){
	vector<node> v;
	int n;
	while( scanf("%d", &n) != EOF){
		if( n == 0){
			break;
		}
		v.clear();
		for(int i=0; i<n; i++){
			node temp;
			scanf("%d", &temp.value);
			v.push_back(temp);
		}
		sort(v.begin(), v.end(), cmp);
		for(int i=0;i<n;i++){
			printf("%d ",v[i].value);
		}
		printf("\n");
	}
	return 0;
}
