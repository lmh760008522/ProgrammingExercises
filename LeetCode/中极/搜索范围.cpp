#include<cstdio>
int main(){
	//int a[6]={5,7,7,8,8,10};
	//int tar = 8;
	
	//int a[6]={5,7,7,8,8,8};
//	int tar = 8;
	
	int a[6]={5,7,7,8,8,8};
	int tar = 5;
	
	int n=6;
	int l=0,r=5,m;
	int ll,rr;
	while(l<=r){
		m=(l+r)/2;
		if(a[m]==tar) { 
			if(a[0]==tar){
				ll=0;
				break;
			}else if(a[m-1]<a[m]){
				ll=m;
				break;
			}
		}
		if(a[m]>tar || (a[m]==tar && a[m-1]==a[m]) ){
			r=m;
		}else if ( a[m]<tar){
			l=m+1;
		}
	}
	
	l=0,r=5;
	while(l<=r){
		m=(l+r)/2;
		if(a[m]==tar){ 
			if(a[n-1]==tar){
				rr=n-1;
				break;
			}else if(a[m+1]>a[m]){
				rr=m;
				break;
			}
		}
		if(a[m]>tar ){
			r=m;
		}else if ( a[m]<tar || (a[m]==tar && a[m+1]==a[m]) ){
			l=m+1;
		}
	}
	
	printf("%d %d",ll,rr);
	
	return 0;
}
