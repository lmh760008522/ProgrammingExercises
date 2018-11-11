#include<stdio.h>

int map[1000] = {-1};

int find(int x){
	while(map[x]!=-1){
		return find(map[x]);
	}
	return x;
}

int main(){
	int n,m;
	while(scanf("%d",&n) != EOF){
		if( n == 0){
			break;
		}
		scanf("%d", &m);
		for(int i=0;i<=n;i++){
			map[i] = -1;
		}
		
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d", &a,&b);
			a = find(a);
			b = find(b);
			if(a != b){
				map[a] = b;
			}
		}
		
		int cnt = 0;
		for(int i=1; i<=n; i++){
			if(map[i] == -1){
				cnt++;
			}
		}
		
		printf("%d\n", cnt-1);
	}
} 
