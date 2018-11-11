#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	double a[1001];
	for(int i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	int dpmax[1001]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>=a[j]){
				dpmax[i]=max(dpmax[i],dpmax[j]+1);
			}
		}
	}
	int dpmin[1001]={0};
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(a[i]>=a[j]){
				dpmin[i]=max(dpmin[i],dpmin[j]+1);
			}
		}
	}
	int max=0;
	for(int i=0;i<n;i++){
		printf("%d %d\n",dpmax[i],dpmin[i]);
		if(max < dpmax[i]+dpmin[i]){
			max=dpmax[i]+dpmin[i];
		}
	}
	printf("%d\n",n-max);
	return 0;
}
