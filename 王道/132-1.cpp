#include<cstdio>
int main(){
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			for(int k=0;k<10;k++){
				if(100*i+10*j+k+100*j+10*k+k==532){
					printf("%d %d %d\n",i,j,k);
				}
			}
		}
	}
	return 0;
}
