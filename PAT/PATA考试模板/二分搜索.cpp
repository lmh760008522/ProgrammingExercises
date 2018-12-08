//二分搜索 
#include<iostream>
#include<vector>
using namespace std;
#define MAX 9

int a[MAX] = {0,2,5,7,9,21,65,99,146};

void bsearch(int val){//迭代法 
	int mid, low = 0, high = MAX-1;
	int x = -1;
	while(low <= high){
		mid = (low + high)/2;
		if(val < a[mid]){
			high = mid - 1;
		}else if(val > a[mid] ){
			low = mid + 1;
		}else{
			x = mid;
			break;
		}
	}
	if(x == -1) cout<<"not exist"<<endl;
	else cout<<x<<endl;
}

int main(){
	
	bsearch(0);
	bsearch(146);
	bsearch(65);
	bsearch(20);
	
	return 0;
} 
