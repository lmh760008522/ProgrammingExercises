#include<cstdio>
#include<string>
//#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[3];
	string c;
	while( scanf("%d %d %d",&a[0],&a[1],&a[2]) != -1){
		//printf("?");
		sort(a,a+3);//从小到大排序
		for(int i=0;i<3;i++){
			c+=(a[i]+'0');
		}
		if(c=="123" || c=="135" ||c=="145" || c=="124" || c=="246" || c=="236" || c=="356"|| c=="456"){
			printf("0\n");
		} else if( c=="126" || c=="256" || c=="156" ||c=="125" ){
			printf("3\n");
		}else if(c=="234" || c=="235" || c=="345" || c=="245"){
			printf("1\n");
		}else if(c=="136"||c=="346" || c=="146" || c=="134"){
			printf("2\n");
		}
	}	
	return 0;
} 
