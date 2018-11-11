#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int w[100001];
	int a[100001];
	int i;
	long long ans=0;
	while( scanf("%d",&n) !=-1 ){
		for(i=0;i<n;i++){
			scanf("%d",&w[i]);
			a[i]=1;
		}
		for(i=1;i<n-1;i++){
			if(w[i]>w[i-1] && w[i]>w[i+1]){//1 3 2  || 2 3 1
				a[i]=max(a[i-1],a[i+1])+1;
			}else if(w[i]<w[i+1] && w[i]>w[i-1]){//1 2 3
				if(a[i]<=a[i-1]) a[i]=a[i-1]+1;
				if(a[i+1]<=a[i]) a[i+1]=a[i]+1;
			}else if(w[i-1]>w[i] && w[i]>w[i+1]){//3 2 1
				if(a[i]<=a[i+1]) a[i]=a[i+1]+1;
				if(a[i-1]<=a[i]) a[i-1]=a[i]+1;
			}else if(w[i]<w[i+1] && w[i]<w[i-1]){// 2 1 3 || 3 1 2
				if(a[i-1]<=a[i]) a[i-1]=a[i]+1;
				if(a[i+1]<=a[i]) a[i+1]=a[i]+1;
			}
		}
		ans=0;
		for(i=0;i<n;i++){
			//printf("%d ",a[i]);
			ans+=a[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
 
