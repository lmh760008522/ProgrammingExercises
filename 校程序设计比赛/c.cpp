/*
1
1
100 1
50 1
30 5 
这个就是错的，所以贪心不可行 
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct node{
	int time;//100
	int num;//5
}node;

bool cmp(node a,node b){
	return a.time>b.time;
}

int main(){
	int t;//10
	int n;//20
	int i,j,temp;
	node hw[20];
	int mint,leftt;
	scanf("%d",&t);
	while( (t--) > 0){
		scanf("%d",&n);
		mint=0;
		leftt=0;
		temp=0;
		for(i=0;i<n;i++){
			scanf("%d %d",&hw[i].time,&hw[i].num);
		}
		sort(hw,hw+n,cmp);//从大到小排序 
		for(i=0;i<n;i++){
			if(leftt==0){
				mint+=hw[i].num/2*hw[i].time;
				if(hw[i].num %2==1){
					leftt+=hw[i].time;
					mint+=leftt;
				}
			}else{
				for(j=i;j<n;j++){//先解决Left 
					if(hw[j].time < leftt){
						if(hw[j].num > leftt/hw[j].time){
							hw[j].num-=leftt/hw[j].time;
							leftt-=hw[j].time*(leftt/hw[j].time);
						}else{
							leftt-=hw[j].time*hw[j].num;
							hw[j].num=0;
						}
					}
				}
				if(leftt==0){
					i--;
					continue;
				}else{
					temp=mint;
					mint-=leftt;
					mint+=hw[i].num/2*hw[i].time;
					if(temp<mint){
						leftt=mint-temp;
					}else{
						leftt=temp-mint;
						mint=temp;
					}
				}
			}
		}
		cout<<mint<<endl;
	}
	
	return 0;
}
