#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;

int totaltime[20000];//个人时间 
int sumtime[20000];//团队时间 
int sumnum[20000];//团队人数 
int tree[20000];

typedef struct node{
	char name[4];
	int member;
}node; 

int todigit(char *name){
	int ans=0;
	for(int i=0;i<3;i++){
		ans*=26;
		ans+=name[i]-65;
	}
	return ans;
}

char* tonum(int x){
	char name[3];
	for(int i=2;i>=0;i--){
		name[i]=x%26;
		x=x/26;
	}
	return name;
}

int findroot(int x){
	if(tree[x]==-1){
		return x;
	}else{
		int temp=findroot(tree[x]);
		tree[x]=temp;
		return temp;
	}
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	memset(totaltime,0,sizeof(totaltime));
	memset(sumtime,0,sizeof(sumtime));
	for(int i=0;i<=n;i++){
		sumnum[i]=1;
		tree[i]=-1;
	}
	for(int i=0;i<n;i++){
		char name1[3],name2[3];
		int time;
		scanf("%s %s %d",name1,name2,&time);
		int a=todigit(name1);
		int b=todigit(name2);
		totaltime[a]+=time;
		totaltime[b]+=time;
		//sumtime[a]+=time;
		//sumtime[b]+=time;
		a=findroot(a);
		b=findroot(b);
		if(a!=b){//小的连大的 
			if(sumtime[b]>sumtime[a]){
				tree[a]=b;
				sumtime[b]+=sumtime[a];
				sumnum[b]+=sumnum[a];
			}else{
				tree[b]=a;
				sumtime[a]+=sumtime[b];
				sumnum[a]+=sumnum[b];	
			}
		} 
	}
	int sumbang;
	vector<node> ans;
	for(int i=1;i<=n;i++){
		if(tree[i]==-1 && sumnum[i]>=3 && sumtime[i]>=k){
			sumbang++;
			node d;
			d.member=sumnum[i];
			d.name=tonum(i);
			ans.push_back(d);
		}
	}
	//dayin
	
	return 0;
}
