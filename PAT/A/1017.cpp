#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct node{
	int h,m,s;
	int pre;
	bool flag;
}node;
vector<node> cus;
vector<int>  window;  
bool cmp(node a,node b){
	if(a.h==b.h){
		if(a.m==b.m){
			return a.s<b.s;
		}
		return a.m<b.m;
	}
	return a.h<b.h;
}
int main(){
	int n,k;
	cin>>n>>k;
	cus.reserve(n);
	int count=n;
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d", &cus[i].h, &cus[i].m, &cus[i].s, &cus[i].pre);//¶ÁÈë×¢Òâ 
		cus[i].flag=true;
		if(cus[i].h<8){
			cus[i].h=8;
			cus[i].m=0;
			cus[i].s=0;
		}else if(cus[i].h==17 && (cus[i].m>0 || cus[i].s>0)){
			cus[i].flag=false;
			count--;
		}
	}
	sort(cus.begin(),cus.end(),cmp);
	
	cout<<cus.size()<<endl;
	
	int sum=0;
	window.resize(k);
	for(int i=0;i<k;i++){
		if(cus[i].flag == true){
			window[i]=(cus[i].h-8)*3600+cus[i].m*60+cus[i].s+cus[i].pre*60;
		}
	}
	for(int i=3;i<cus.size();i++){
		sort(window.begin(),window.end());
		if(cus[i].flag == true){
			sum+=(cus[i].h-8)*3600+cus[i].m*60+cus[i].s-window[0];
			window[0]+=cus[i].pre*60;
		}	
	}
	cout<<window[0]<<" "<<window[1]<<" "<<window[2]<<" "<<endl; 
	if(cus.size() == 0)
        printf("0.0");
    else
        printf("%.1f", sum / 60.0 / count);
	return 0;
}
