#include<cstdio>
using namespace std;
/*
�ȶԾ������ɨ�裬���Ҫ������0���к��У���Ҫ������0�����ڵ�0���Ͻ��б�ǣ�����0�����ڵ�0���Ͻ��б��ǡ�ͬʱ��Ҫ��������¼��0�к͵�0���Ƿ�Ҫ��0����������0������ 
*/ 
int main(){
	//int m=3,n=3;
	//int a[100][100]={ {1,1,1},{1,0,1}, {1,1,1}};
	int m=3,n=4;
	int a[100][100]={{0,1,2,0}, {3,5,4,2}, {1,3,1,5}};
	/* 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &a[i][j]);
		}
	}*/ 
	bool col=false,row=false; 
	for(int i=0; i<m; i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==0){
				if(i==0){
					row=true;
				}
				if(j==0){
					col=true;
				}
				a[i][0]=0;//�ڵ�0���ϱ�� 
				a[0][j]=0;//�ڵ�0���ϱ�� 
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if( (a[i][0]==0&&i!=0) || (a[0][j]==0&&j!=0) ){
				a[i][j]=0;
			}
		}
	}
	/*
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	if(row){
		for(int i=0;i<n;i++){
			a[0][i]=0;
		}
	}
	if(row){
		for(int j=0;j<m;j++){
			a[j][0]=0;
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
