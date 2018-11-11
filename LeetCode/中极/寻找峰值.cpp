#include<cstdio>
using namespace std;
int main(){
	int a[4]={1,2,3,1};
	int l=0,r=3;
	
	while(l<=r){
		if(l==r){
			printf("%d",l);
			break;
		}
		int m=(l+r)/2;
		if(a[m] < a[m+1]){
			l=m+1;
		}  else{
			r=m;
		}
	}
	return 0;
}
