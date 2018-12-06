/*
尺取法 
找到所有和为m的连续子序列。
若找不到， 找到大于m的最小和 ，输出所有结果。 
*/
#include<iostream>
#include<vector>
using namespace std;

typedef struct node{
	int p,q;
}node;

int main(){
	int n, m; // n<=10^5, m<=10^8
	cin>>n>>m;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	bool flag = false;
	int sum = 0;
	for(int p=0,q=0; p<n && q<n+1; ){ 
		if( sum == m){
			cout<<p+1<<"-"<<q<<endl;
			flag = true;
			sum -= v[p];
			p++;
		}else if(sum < m){
			sum += v[q];
			q++;
		}else{
			sum -= v[p];
			p++;
		}
	}
	
	if(!flag){
		vector<node> ans;
		int sum = 0, min = 99999999;
		for(int p=0,q=0; p<n && q<n+1; ){ 
			if( sum > m){
				//cout<<sum<<" "<<min<<endl;
				if(sum < min){
					min = sum;
					ans.clear();
					node temp;
					temp.p = p+1, temp.q = q;
					ans.push_back(temp);
				}else if(sum == min){
					node temp;
					temp.p = p+1, temp.q = q;
					ans.push_back(temp);
				}
				sum -= v[p]; 
				p++;
			}else if(sum < m){
				sum += v[q];
				q++;
			}else{
				sum -= v[p];
				p++;
			}
		}
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i].p<<"-"<<ans[i].q<<endl;
		} 
	}
	return 0;
} 
