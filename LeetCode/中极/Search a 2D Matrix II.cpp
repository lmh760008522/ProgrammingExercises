#include<cstdio>
int main(){
	int a[5][5]={{1,   4,  7, 11, 15},
			   {2,   5,  8, 12, 19},
			   {3,   6,  9, 16, 22},
			   {10, 13, 14, 17, 24},
			   {18, 21, 23, 26, 30}};
//	int tar=20;
	int tar=1;
//	int tar=24;
	int m=5,n=5;
	int x1=0,y1=n-1;
	int x2=m-1,y2=0;
	
	bool flag=false;
	while(true){
		if(x1==x2 && y1==y2 && a[x1][y1]!=tar){
			break;
		}
		if(a[x1][y1]==tar || a[x2][y2]==tar){
			flag=true;
			break;
		}
		if(a[x1][y1]<tar){
			x1++;
		}else{
			y1--;
		}
		
		if(a[x2][y2]<tar){
			y2++;
		}else{
			x2--;
		}
	}
	printf("%d",flag);
	return 0;
}
