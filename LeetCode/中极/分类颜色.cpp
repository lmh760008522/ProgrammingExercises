#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int a[6]={2,0,2,1,1,0};
	int l=0,r=5;
	int n=3;
	int lc=0,rc=n-1;
	for(int i=1;i<=n/2;i++){
		for(int j=l;j<=r;j++){
			if(a[j]==lc){
				swap(a[l],a[j]);
				l++;
			}
			if(a[j]==rc){
				swap(a[r],a[j]);
				r--;
			}
		}
		lc++;
		rc--;
	}
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
