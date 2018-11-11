//you bug 
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int relation[10000][10000];
typedef struct node{
	int id1,id2;
}no;
vector< node> ans;

bool cmp(no a,no b){
	if(a.id1 == b.id2){
		return a.id2<b.id2;
	}
	return a.id1<=b.id2;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if( a * b <0){
			a=abs(a);
			b=abs(b);
			relation[a][b]=relation[b][a]=-1;
		}else{
			a=abs(a);
			b=abs(b);
			relation[a][b]=relation[b][a]=1;
		}
	}
	
	int k;
	cin>>k;
	
	for(int i=0;i<k;i++){
		ans.clear();
		int u,v;
		cin>>u>>v;
		int a=abs(u),b=abs(v);
		int flag=1;
		if(a*b<0){
			flag=-1;
		}
		for(int j=1000;j<10000;j++){
				if(relation[a][j]==1){
					for(int k=1000;k<10000;k++){
						if(relation[j][k]==flag){
							if(relation[k][b]==1){
								no kk;
								kk.id1=j;
								kk.id2=k;
								//cout<<j<<" "<<k<<endl;
								ans.push_back(kk);
							}
						}
					}
				}
		}
		sort(ans.begin(),ans.end(),cmp);
		cout<<ans.size()<<endl;
		for(int j=0;j<ans.size();j++){
			cout<<ans[j].id1<<" "<<ans[j].id2<<endl;
		}
	}
	return 0;
}
