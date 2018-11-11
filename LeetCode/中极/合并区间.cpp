#include<cstdio>

typedef struct node{
	int l,r;
}node;

int main(){
	int n;
	node give[4];
	node ans[4];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		give[i].l=a;
		give[i].r=b;
	}
	//ÅÅÐò£¬°´ÕÕl 
	int j=0;
	ans[j].l=give[0].l;
	ans[j].r=give[0].r;
	for(int i=1;i<n;i++){
		if(give[i].l<=ans[j].r){
			ans[j].r=give[i].r;
		}else{
			j++;
			ans[j].l=give[i].l;
			ans[j].r=give[i].r;
		}
	}
	for(int i=0;i<=j;i++){
		printf("(%d,%d) ",ans[i].l,ans[i].r);
	}
	return 0;
} 
