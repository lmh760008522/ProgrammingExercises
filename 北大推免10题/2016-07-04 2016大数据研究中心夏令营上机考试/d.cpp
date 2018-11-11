#include<cstdio>

int m,n;
int ans=0;

int f(int m,int n){
	if( n==1 || m==1 || n==0){
		return 1;
	}
	if(m<n){
		return f(m,m);
	}else{
		return f(m-n,n)+f(m,n-1);
	}
}

int main(){
	scanf("%d %d",&m,&n);
	ans = f(m,n);
	printf("%d\n",ans);
	return 0;
}
