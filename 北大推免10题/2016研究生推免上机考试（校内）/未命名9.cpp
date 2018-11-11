#include<cstdio>
#include<algorithm>
using namespace std;

int a[5000001];
int visit[5000001]={0};

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int step=0;
	step+=a[i];
	visit[i]=1;
	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j++){
			
		}
	}
	return 0;
}
