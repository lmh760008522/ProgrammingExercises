#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[2001];
	//int b[2001];
	int dp[1001][2001]; //前j件物品选择i对的最小疲劳度 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	/*另一种思路：设定struct ，记录左物品，右物品，差值，然后排序；从小到大选择不冲突的 
	for(int i=1;i<n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	sort(b,b+n-1);
	int ans=0;
	for(int i=0;i<k)
	*/
	for(int i=1;i<=n;i++){
		dp[i][0]=0;
		dp[i][1]=0;
	} 
	for(int i=0;i<=n;i++){
		dp[0][i]=0;
	}
	dp[1][2]=(a[2]-a[1])*(a[2]-a[1]);
	for(int j=3;j<=n;j++){
		for(int i=1;2*i<=j;i++){
			if(j!=2*i){
				dp[i][j] = dp[i][j-1] > ( dp[i][j-2] + (a[j]-a[j-1])*(a[j]-a[j-1]) ) ? ( dp[i][j-2] + (a[j]-a[j-1])*(a[j]-a[j-1]) ):  dp[i][j-1];
			}else{
				
			}
		}
	}
	return 0;
}
