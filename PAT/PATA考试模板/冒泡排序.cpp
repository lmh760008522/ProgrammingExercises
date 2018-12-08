//冒泡排序 最好n-1次比较O(n), 最坏，逆序，O(n^2) 
#include<iostream>
#include<vector>
#define MAX 9
using namespace std;

int main(){
	int a[MAX] = {5,3,1,3,4,2,1,3,8};
	for(int i = MAX-1; i >= 0; i--){ //最多 MAX-1 趟 
		int last = 0;
		for(int j = 0; j < MAX -1; j++){
			if(a[j+1] < a[j]){
				int t = a[j+1];
				a[j+1] = a[j];
				a[j] = t;
				last = j;
			}
		}
		i = last; 
	}
	for(int i=0;i<MAX;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 
