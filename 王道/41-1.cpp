#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	int a[100];
	while(t-- >0){
		int n,p,w;
		scanf("%d %d %d",&n,&p,&w);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int ans=a[0];
		int maxv=p;
		if(ans>w){
			printf("0 0.00\n");
			continue;
		}
		for(int i=1;i<n;i++){
			//printf("%lf %lf\n",(ans+a[i])/double(maxv+p),double(w)/100);
			if( (ans+a[i])/double(maxv+p) <= double(w)/100){
				ans+=a[i];
				maxv+=p;
			//	printf("%d %d\n",ans,maxv);
				if( ans/double(maxv) == double(w)/100){
					break;
				}
			}else{
				break;
			}
		}
		printf("%d %.2f\n",maxv,ans/double(maxv));
	}
	return 0;
}
