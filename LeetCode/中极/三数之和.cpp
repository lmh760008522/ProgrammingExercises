#include<cstdio>
#include<algorithm>
#include<vector> 
#include<set>
using namespace std;

typedef struct node{
	int a,b,c;
}node; 

int main(){
	int a[6]={-1, 0, 1, 2, -1, -4};
	set<node> ans;
	vector<int> nums(a,a+6);
	sort(nums.begin(), nums.end());//¥”µÕµΩ∏ﬂ≈≈–Ú
	int k=0;
	for(int i=0;i+1<6;i++){
		if(nums[i]==nums[i-1]){
			//printf("?");
			continue;
		}
		for(int j=i+1;j<6;j++){
			if( binary_search(nums.begin()+j+1,nums.end(),0-nums[i]-nums[j])){
				node n;
				n.a=nums[i]; n.b=nums[j]; n.c=0-nums[i]-nums[j];
					printf("[%d, %d, %d]\n",n.a, n.b,n.c);
				//ans.insert(n);
			}
		}
	} 
	/*
	set<node>::iterator it=ans.begin();
	for( ; it!=ans.end(); it++){
		printf("[%d, %d, %d]\n",it->a, it->b,it->c);
	}*/
	return 0;
}
