#include<stdio.h>
#include<vector>
#include<math.h>
#include<iostream>
using namespace std;
int main(){
	int k;
	scanf("%d",&k);
	for( ;k>0;k--){
		int n;
		cin>>n;
		vector<int> a(n);
		bool result = true;
		for(int i=0;i<n;i++){
			cin>>a[i];
			for(int j=0;j<i;j++){
				if(a[j]==a[i]||abs(a[j]-a[i])==abs(j-i)){
					result = false;
				}
			}
		}
		if(result){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
} 
