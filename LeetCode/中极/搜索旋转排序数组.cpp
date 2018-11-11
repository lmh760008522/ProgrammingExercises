#include<cstdio>
int main(){
	int a[8]={4,5,6,7,0,1,2};
	int n=8;
	int l=0,r=7,m;
	//int tar=4;
	//int tar=7;
	//int tar=0;
	int tar=9;
	while(l<=r){
		m=(l+r)/2;
		if(a[m]>a[m+1]){
			break;
		}else{
			if(a[m]>a[l] && a[m]>a[r]){
				l=m;
			}else if(a[m]<a[r] && a[m]<a[l]){
				r=m;
			}
		}
	}
	if(tar>=a[0]){
		l=0;
		r=m;
	}else{
		l=m+1;
		r=n-1;
	}
	while(l<=r){
		m=(l+r)/2;
		if(a[m]>tar){
			r=m;
		}else if(a[m]<tar){
			l=m+1;
		}else{
			break;
		}
	}
	if(l>r){
		printf("-1");
	}else{
		printf("%d",m);
	}
	return 0;
}
