#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

typedef struct point{
	double x,y;
	int id;
}point;

typedef struct node{
	int l,r;
	double way;
}node;

bool cmp(node a,node b){
	return a.way<b.way;
}

vector<point> points;
vector<node> edges;
int visit[1000];

int main(){
	int n;
	scanf("%d",&n);
	memset(visit,0,sizeof(visit));
	
	for(int i=0;i<n;i++){
		double a,b;
		scanf("%lf %lf",&a,&b);
		point temp;
		temp.x=a;
		temp.y=b;
		temp.id=i;
		points.push_back(temp);
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			node temp;
			temp.l=points[i].id;
			temp.r=points[j].id;
			temp.way= sqrt( pow(points[i].x-points[j].x,2)+pow(points[i].y-points[j].y,2));
			edges.push_back(temp);
		}
	}
	
	sort(edges.begin(),edges.end(),cmp);
	
	double ans=0;
	for(int i=0;i<edges.size();i++){
		if(visit[edges[i].l] == 0 || visit[edges[i].r] == 0){
			visit[edges[i].l] =1;
			visit[edges[i].r] =1;
			ans+=edges[i].way;
		}
	}
	printf("%.2lf\n",ans);
	
	return 0;
}
