//最长公共子序列
#include<iostream>
#include<vector>
#define MAX1 9 
#define MAX2 7 
using namespace std;

int main(){
	int a[MAX1+1] = {0,0,1,2,3,4,5,6,7,8};
	int b[MAX2+1] = {0,9,1,2,6,3,4,5} ;
	int dp[MAX1+1][MAX2+1];
	for(int i = 0; i <= MAX1; i++){
		dp[i][0] = 0; 
	} 
	for(int j = 0; j <= MAX2; j++){
		dp[0][j] = 0; 
	} 
	for(int i = 1; i <= MAX1; i++){
		for(int j = 1; j <= MAX2; j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout<<dp[MAX1][MAX2];
	return 0;
}  
