/*
8皇后问题：任意两个皇后不能在同一个竖线、横线、斜线上
判断是否是N皇后成立 
*/ 
#include<stdio.h>
#include<math.h>
int main(){
	int k;
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		int n;
		scanf("%d", &n);
		int a[1005];
		bool table[1005] = {false};
		bool flag = true;
		for(int j=1;j<=n;j++){
			scanf("%d", &a[j]);
			if(table[a[j]] == false){//检查是否有在同一列的 
				table[a[j]] = true;
			}else{
				flag = false;
				//printf("1 ");
			}
		}
		for(int p=1;p<=n;p++){//检查是否在一个对角线 
			for(int q=p+1;q<=n;q++){
				if(abs(p-q) == abs(a[p]-a[q])){
					flag = false;
					break;
				} 
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
