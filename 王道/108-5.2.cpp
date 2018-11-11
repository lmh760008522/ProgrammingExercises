#include<cstdio>
#include<string.h>
int tree[100000001];
int sum[100000001];

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
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		tree[i]=-1;
		sum[i]=1;
	}
	while(n-- >0){
		int a,b;
		scanf("%d %d",&a,&b);
		a=findroot(a);
		b=findroot(b);
		if(a!=b){
			tree[a]=b;
			sum[b]+=sum[a];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(tree[i]==-1 && (ans<sum[i])){
			ans=sum[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
