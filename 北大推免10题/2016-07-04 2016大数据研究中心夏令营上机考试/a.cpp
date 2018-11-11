#include<cstdio> 
int main(){
	int w;
	char flag;
	scanf("%d %c",&w,&flag);
	int ans=0;
	if(w<=1000){
		ans+=8;
	}else{
		ans+=8;
		ans+=(w-1000)/500 *4;
		if(w%500!=0){
			ans+=4;
		}
	}
	if(flag=='y'){
		ans+=5;
	}
	printf("%d\n",ans);
	return 0;
}
