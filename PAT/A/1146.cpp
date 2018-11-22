//topological order£∫Õÿ∆À–Ú 
//permutation: ÷√ªª 
#include<stdio.h>
#include<vector>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int tree[1005] ={0};
	vector< vector<int> > v(n+1);
	for(int i=0;i<m;i++){
		int start, end;
		scanf("%d %d",&start, &end);
		tree[end]++;
		v[start].push_back(end);
	}
	int k;
	scanf("%d", &k);
	vector<int> ans;
	int count[1005];
	for(int i=0;i<k;i++){
		bool flag = false;
		for(int j=0;j<=n;j++){
			count[j] = tree[j];
		}
		for(int j=0;j<n;j++){
			int x;
			scanf("%d", &x);
			if(flag == false){
				if( count[x] != 0){
					flag = true;
					ans.push_back(i);
				}else{
					for(int k = 0; k<v[x].size();k++){
						count[ v[x][k] ]--;
					}
				}
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		if(i != 0){
			printf(" ");
		}
		printf("%d",ans[i]);
	}
	return 0;
} 
