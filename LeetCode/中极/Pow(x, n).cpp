#include<cstdio>
#include<algorithm>
#include<cmath>
int main(){
	int n;
	double x;
	scanf("%lf %d",&x,&n);
	double ans=x;
	if(n==0){
		printf("%lf",x);
		return 0;
	}
	
		//double tmp=1;
		double tmpans=x;
		int nn=n;//¼ÇÂ¼Ò»ÏÂ 
		n=abs(n);
		while(n>0){
			int i=n & 1;
			if(i==1){
				ans*=tmpans;
			}
			n=n>>1;
			//tmp=tmp*2;
			tmpans=tmpans*tmpans;
		}
		ans/=x;
	
	if(nn>0){
		printf("%lf",ans);
	}else{
		printf("%lf",1/ans);
	}
	return 0;
}
