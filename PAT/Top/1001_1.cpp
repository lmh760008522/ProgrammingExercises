#include<cstdio>
#include<vector>
#include<algorithm> 
using namespace std;

typedef struct edge{
	int x, y ,c;
	edge(int x0,int y0,int c0){
		x=x0;
		y=y0;
		c=c0;
	}
	bool friend operator <(struct edge a,struct edge b){
		return a.c<b.c;
	}
}Edge;

int f[501];
int find(int x){
	return x==f[x]?x:find(f[x]);
}

int main(){
	int n,m,x,y,c,sta;
	vector<int> ans;
	vector<Edge> edge;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++){//�������Ϣ 
		scanf("%d %d %d %d",&x,&y,&c,&sta);
		Edge e(x,y,sta?0:c);//����ͨ�У���COST=0
		edge.push_back(e);
	}
	
	sort(edge.begin(),edge.end());//���߰���cost��С��������
	
	for(int i=1;i<=n;i++){//����ȥ��ÿһ������ 
		int cost=0;
		
		for(int j=1;j<=n;j++){
			f[j]=j;
		}
		for(int j=0;j<m;j++){//��С��������ÿһ���� 
			if(edge[j].x==i||edge[j].y==i) continue;//���������i�ıߣ���ʾȥ������
			int xs = find(edge[j].x);
			int ys = find(edge[j].y);
			if(xs != ys){//���������û����ͨ 
				f[ys]=xs;//��ͨ��
				cost+=edge[j].c;//���㻨�� 
			}
		}
		if(cost!=0){
			ans.push_back(i);
		}
	}
	
	if(ans.empty()){
		puts("0");
	}else{
		int maxCost =0;
		for(int i=0;i<ans.size();i++){
			if(ans[i]>maxCost){//�ҵ����ֵ 
				maxCost=ans[i];
			}
		}
		for(int i=0;i<ans.size();i++){
			int flag=0;
			if(ans[i]==maxCost){//�ҵ����ֵ 
				if(flag==0){
					printf("%d");
					flag=1;
				}else{
					printf(" %d");
				}
				
			}
		}
	}
	
	return 0;
}
