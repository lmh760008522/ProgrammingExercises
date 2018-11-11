#include<cstdio>
int sumNum10(int t){
	int ans=0;
	while(t!=0){
		ans+=t%10;
		t=t/10; 
	}
	return ans;
}

int sumNum2(int t){
	int ans=0;
	while(t!=0){
		ans+=t&1;
		t=t>>1;
	}
	return ans;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int m;
		scanf("%d",&m);
		
		int num=0;
		for(int j=1;j<=m;j++){
			int ans10=sumNum10(j);
			int ans2=sumNum2(j);
			if(ans10 == ans2){
				num++;
			}
		}
		printf("%d\n",num);
	}
	return 0;
} 
