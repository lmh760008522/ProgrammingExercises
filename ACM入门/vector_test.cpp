//测试假如vector中不push任何东西的时候，可以打印出什么 
#include<vector>
#include<stdio.h>
using namespace std;

int main(){
	vector< vector<int> > a(2);
	a[1].push_back(1);
	for(int i=0;i<2;i++){
		for(int j=0;j<a[i].size();j++){
			printf("??%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
