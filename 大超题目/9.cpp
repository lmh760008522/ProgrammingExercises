//̰�� 
//�Ҹо�����Ŀ��˼�����ˡ������� 
#include<cstdio>
int main(){
	int t;
	scanf("%d",&t);
	int n;
	scanf("%d\n",&n);
	int city[105];
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&city[j]);
		}
		
		int ans=0;
		for(int j=0;j<n-1;j++){
			if(city[j+1]>city[j]){
				ans+=city[j+1]-city[j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
