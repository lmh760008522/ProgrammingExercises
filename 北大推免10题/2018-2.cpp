#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	char st[100];
	int num;
	int id;
}node;
vector<node> v;

int max(int a,int b){
	return a>b?a:b;
}

bool cmp(node a,node b){
	if(a.num==b.num){
		return a.id<b.id;
	}
	return a.num<b.num;
}

int main(){
	int m;
	scanf("%d\n",&m);
	for(int q=0;q<m;q++){
		char s[100];
		gets(s);
		node temp;
		strcpy(temp.st,s);
		temp.id=q;
		int dp[100]={0};
		dp[strlen(s)-1]=0;
		for(int i=strlen(s)-2 ;i>=0;i--){
			for(int j=strlen(s)-1; j>i;j--){
				if(s[i]>s[j]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		int ans=0;
		for(int i=0;i<strlen(s);i++){
			//printf("%d ",dp[i]);
			ans+=dp[i];
		}
		//printf("\n");
		temp.num=ans;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp); 
	for(int i=0;i<m;i++){
		printf("%d %s\n", v[i].num, v[i].st);
	}
	return 0;
}
