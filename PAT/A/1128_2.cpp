/*
8�ʺ����⣺���������ʺ�����ͬһ�����ߡ����ߡ�б����
�ж��Ƿ���N�ʺ���� 
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
			if(table[a[j]] == false){//����Ƿ�����ͬһ�е� 
				table[a[j]] = true;
			}else{
				flag = false;
				//printf("1 ");
			}
		}
		for(int p=1;p<=n;p++){//����Ƿ���һ���Խ��� 
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
