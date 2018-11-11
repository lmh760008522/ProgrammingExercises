#include<cstdio>
#include<set>
using namespace std;

int change(int n){
	int ans=0;
	int a=0;
	while(n>0){
		a=n%10;
		ans+=a*a;
		n=n/10;
	}
	return ans;
}

int main(){
	int n;
	set<int> s;
	scanf("%d",&n);
	/*
	s.insert(n);
	while(n!=1){
		int m=change(n);
		//printf("%d\n",m);
		if(s.count(m)!=0 ){
			printf("%d",-1);
			return 0;
		}else{
			s.insert(m);
			n=m;
		}
	}
	printf("yes");
	*/
	
	//其实这道题也可以不用set来做，关于非快乐数有个特点，循环的数字中必定会有4
	while(n!=1 && n!=4){
		int t=0;
		while(n){
			t+=(n%10)*(n%10);
			n=n/10;
		}
		n=t;
	}
	if(n==1){
		printf("yes");
	}else{//n=4会出现循环 
		printf("no");
	}
	return 0;
}
