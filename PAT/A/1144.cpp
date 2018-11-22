#include<stdio.h>
#include<map>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	bool flag = false;//记录是否全为0 
	map<int,bool> m;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x>0){
			flag = true;
			m[x] = true;
		} 
	}
	int i = 0;
	if(flag == false){
		printf("1\n"); //全为<=0的数，输出1 
	}else{
		while(++i){
			if(m[i] == false){
				printf("%d\n",i);
				break;
			}
		}
	}

	return 0;
} 
//思考set超时的原因 
