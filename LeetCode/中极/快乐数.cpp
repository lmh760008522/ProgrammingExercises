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
	
	//��ʵ�����Ҳ���Բ���set���������ڷǿ������и��ص㣬ѭ���������бض�����4
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
	}else{//n=4�����ѭ�� 
		printf("no");
	}
	return 0;
}
