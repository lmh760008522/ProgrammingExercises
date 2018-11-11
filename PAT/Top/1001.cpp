//������ȱ��һ�����ʣ�µĵ�������С�������Ĵ��ۡ� ����Խ��ȱ�ĵ�ļ�ֵԽ�����ʣ�µĵ㲻�������С���������൱�ڴ������޴�

#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef struct edge{
	int begin, end, cost;
	edge(int x, int y , int c){
		begin=x;
		end=y;
		cost=c;
	}
	bool friend operator < (struct edge a, struct edge b){
		return a.cost < b.cost; 
	}
}Edge;

int f[501];
int find(int x){
	return x == f[x]? x:f[x] = find(f[x]);
}

int main(){
	int n, m, x, y, c, sta;
	vector<Edge> edges;
	vector<int> ans;
	
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i++){
		scanf("%d %d %d %d", &x, &y ,&c, &sta);
		Edge e(x,y,sta?0:c);//����ͨ�У���COST=0 
		edges.push_back(e);
	}
	
	sort(edges.begin(), edges.end());
	
	bool thereNecessary = false;
	int maxCost =1;
	
	for(int i=1; i<=n ;i++){
		int need = n-2;//����n-1���� 
		int cost = 0;
		
		/********�㷨�����*********/ 
		for( int j=1; j<=n;j++){
			f[j] =j;
		}
		for(int j = 0; need > 0&&j < m; j++){
			if (edges[j].begin == i || edges[j].end ==i) continue;//���������i�ıߣ���ʾȥ������ 
			int xs = find(edges[j].begin);
			int ys = find(edges[j].end);
			if(xs != ys){
				need--;
				f[ys] =xs;
				cost += edges[j].cost;
			}
		}
		/***************************/
		
		//�¶�Ҳ��ȫ��д��ANS�������ֵ�����Ǹ��Ӷȱ�� 
		if (need >0){
			if(!thereNecessary){
				thereNecessary = true;
				ans.clear();
			}
			ans.push_back(i);
		}else{
			if(thereNecessary){
			}else{
				if(cost > maxCost){
					maxCost = cost;
					ans.resize(1);
					ans[0]=i;
				}else if(cost == maxCost){
					ans.push_back(i);
				}
			}
		}
	}
	if(ans.empty()){
		puts("0");
	}else{
		int sAns = ans.size();
		for(int i=0;i<sAns;i++){
			if (i==0){
				printf("%d",ans[i]);
			}else{
				printf(" %d",ans[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
