#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string> 
using namespace std;

 typedef struct point{
	int x,y;
	double len;
}point;
vector<point> p;

bool cmp(point a,point b){
	if(a.len == b.len){
		return a.x<b.x;
	}
	return a.len<b.len;
}

int main(){
	int a,b;
	cin>>a>>b;
	int n;
	cin>>n;
	p.resize(n);
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
		p[i].len = sqrt( (p[i].x-a)*(p[i].x-a) + (p[i].y-b)*(p[i].y-b) );
	}
	sort(p.begin(), p.end(), cmp);
	
	for(int i=0;i<n;i++){
		cout<<"("<<p[i].x<<","<<p[i].y<<")";
		if(i!=n-1){
			cout<<", ";
		}
	}
	
	return 0;
}
