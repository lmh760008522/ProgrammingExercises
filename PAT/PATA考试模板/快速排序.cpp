//¿ìËÙÅÅĞò  O(n*log_2n) 
#include<iostream>
#include<vector>
#define MAX 9
using namespace std;

int a[MAX] = {5,3,1,7,4,2,0,6,8};

void swap(int x, int y){
	int t = a[x];
	a[x] = a[y];
	a[y] = t;
}

void qsort(int left, int right){
	if(left < right){
		int val = a[left];
		int i = left, j = right + 1;
		do{
			do i++; while(a[i] < val);
			do j--; while(a[j] > val);
			if( i < j ) swap(i,j);
		} while(i < j);
		swap(left, j);
		
		qsort(left, j-1);
		qsort(j+1, right);
	}
	return ;
}

int main(){

	qsort(0,MAX-1);
	 
	for(int i=0;i<MAX;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}  
