// incompatible ²»ÏàÈÝµÄ
#include<map>
#include<vector>
#include<iostream>
using namespace std;
 
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	map<int, vector<int> > map;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for(int i=0;i<m;i++){
		int k;
		scanf("%d", &k);
		vector<int> v(k);
		int table[100001] = {0};
		for(int j=0;j<k;j++){
			cin>>v[j];
			table[v[j]] = 1;
		}
		bool flag = true;
		for(int j=0;j<k && flag;j++){	
			for(int q=0; q < map[v[j]].size();q++){
				if(table[map[v[j]][q]] == 1){
					flag = false;
					break;
				}
			}
		}
		if( flag == true) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
} 
