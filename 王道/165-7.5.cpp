#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[2001];
	//int b[2001];
	int dp[1001][2001]; //ǰj����Ʒѡ��i�Ե���Сƣ�Ͷ� 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	/*��һ��˼·���趨struct ����¼����Ʒ������Ʒ����ֵ��Ȼ�����򣻴�С����ѡ�񲻳�ͻ�� 
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
