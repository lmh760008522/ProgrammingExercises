#include<cstdio>
#include<cmath>
int n;
int a[16][16],visit[16][16]={0};
int count=0,min=0;

void paint(int x,int y){
	if(x-1 >= 0){
		a[x-1][y]=!a[x-1][y];
	}
	if(x+1<n){
		a[x+1][y]=!a[x-1][y];
	}
	if(y-1 >= 0){
		a[x][y-1]=!a[x][y-1];
	}
	if(y+1<n){
		a[x][y+1]=!a[x][y+1];
	}
	count++;
}

void getline(int k){//二进制枚举第一行情况 
	int j=n-1;
	while(j>=0){
		visit[0][j]=k%2;
		k=j>>2;
		j--;
	}
}

bool guess(){//从第二行开始 判断每个点上边的点是否为黄色 如果不是黄色 则涂该点
	for(int i=1;i<n;i++){ 
		for(int j=0;j<n;j++){
			if(a[i-1][j]==0){
				paint(i,j);
			} 
		}
	}
	for(int k=0;k<n;k++){
		if(a[n-1][k]!=1){
			return false;
		}
	}
	if(count < min){
		min = count;
	}
	return true;
}
int main(){
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c;
			scanf("%c",&c);
			if(c=='w'){
				a[i][j]=0;
			}else{
				a[i][j]=1;
			}
		}
	}
	for(int k=0;k<pow(2,n);k++){
		count=0;
		getline(k);
		for(int i=0;i<n;i++){
			if( visit[0][i]==1){
				paint(0,i);
			} 
		} 
		guess();
	}
	if(min != n*n+1){
		printf("%d\n",min);
	}else{
		printf("inf\n");
	}
	return 0;
}
