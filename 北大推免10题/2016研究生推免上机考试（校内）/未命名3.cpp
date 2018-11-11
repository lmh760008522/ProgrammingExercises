#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int h[101]={0},l[101]={0};
	int a[101][101];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			h[i]+=a[i][j];
			l[j]+=a[i][j];
		}
	}
	int j_h=0,j_l=0;
	int j_i=0,j_j=0;
	for(int i=0;i<n;i++){
		if(h[i]%2==1){
			j_h++;
			j_i=i;
		}
	}
	for(int i=0;i<n;i++){
		if(l[i]%2==1){
			j_l++;
			j_j=i;
		}
	}
	if(j_h==0 && j_l==0){
		printf("OK\n");
	}else if(j_h==1 && j_l==1){
		printf("%d %d\n",j_i+1,j_j+1);
	}else{
		printf("Corrupt\n");
	}
	return 0;
}
