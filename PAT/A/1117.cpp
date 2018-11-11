#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v,count;

//超时，换方法 ，没有仔细分析问题，理清思路 
 
int main(){
	int n;//<=100000
	scanf("%d",&n);
	
	v.resize(n);
	count.resize(n+1);
	
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
		for(int j=1;j<=v[i] && j<=n ;j++){
			count[j]++;
		}
	}
	for(int j=n;j>0;j--){
		if(count[j]>=j){
			printf("%d",j);
			break;
		}
	}
	return 0;
}
