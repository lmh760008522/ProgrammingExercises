#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct station{
	double pri;
	double dis;
}sta;


bool cmp(sta a, sta b){
	return a.dis<b.dis;
}
int main(){
	double c_max,d,d_avg;//最大容量，距离，每公里消耗
	int n, i;
	
	scanf("%lf %lf %lf %d",&c_max,&d , &d_avg, &n);
	
	i=1;
	int flag=false;
	vector<sta> l(n+1);
	while(i<=n){
		scanf("%lf %lf",&l[i].pri, &l[i].dis);
		if(l[i].dis == 0){
			flag = true;
		}
		i++;
	}
	
	if(!flag){//若没有距离为0的，则无法出发 
		return 0; 
	}
	
	l[0].dis = d;//给终点拟设加油站 
	l[0].pri = 0;
	
	sort(l.begin() , l.end(),cmp);//从小到大排序 
	
	/* 
	for(i=0;i<n;i++){
		printf("%lf %d\n",l[i].pri,l[i].dis);
	}*/ 
	
	double nowdis=0, maxdis=0, nowprice=0, totalprice=0;
	while(nowdis<d){
		maxdis = nowdis + c_max*d_avg;
		for(i=1 ;i<=n && l[i].dis <= maxdis;i++){
			if(l[i].dis <=nowdis) continue;
			if(l[i].pri < nowprice){
				totalprice +=(l[i].dis - nowdis );
			}
		}

			
	}
	 
	return 0;
}
