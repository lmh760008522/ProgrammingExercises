/*
矩阵填充。 逻辑。 
将N个数按规则以不递增的顺序填充到矩阵中 
第一个字符填充在左上角，然后按照顺时针 （ a clockwise spiral）的方式填充 。
矩阵m行n列，找到m和n，使得m*n == N ，且m>=n, 且m-n是最小值 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool cmp(int a, int b){
	return a>=b;
}

int main(){
	int N;
	cin>>N;
	vector<int> v(N);
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int n, m;
	for(m = ceil(sqrt(N)); m<=N; m++){
		if(N%m == 0){
			n = N/m;
			break;
		}
	}
	//cout<<m<<" "<<n;
	vector< vector<int> > ans(m);
	for(int i=0;i<m;i++){
		ans[i].resize(n);
	}
	
	int count = 0;
	int quan = 0;
	while(count<N){
		for(int j = quan;j<n-quan && count<N;j++){
			ans[quan][j] = v[count++];
		}
		for(int i = quan+1;i<m-quan && count<N;i++){
			ans[i][n-quan-1] = v[count++];
		}
		for(int j = n-quan-2;j>=quan && count<N;j--){
			ans[m-quan-1][j] = v[count++];
		}
		for(int i = m-quan-2;i>quan && count<N;i--){
			ans[i][quan] = v[count++];
		}
		quan++;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(j!=0){
				cout<<" ";
			}
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
} 
