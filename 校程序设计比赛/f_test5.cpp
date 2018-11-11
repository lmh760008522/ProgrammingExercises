//��ȡģ��pС��1e9ʱ,����Ԥ����
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
//����n��k�η���Mȡģ�����ַ�
ll Pow(ll n, ll k, ll p){
	ll ans=1;
	while(k){
		if(k&1)
			ans=(ans*n)%p;
		n = (n*n)%p;
		k>>=1; //k=k>>1  k=k/2��
	}
	return ans;
}
ll C(ll n,ll m,ll p){
	if(m==0) return 1;
	if(m>n-m) m=n-m;
	ll up=1,down=1;
	for(int i=1;i<=m;i++){
		up = (up*(n-i+1))%p;
		down=(down*i)%p;
	}
	return up*Pow(down,p-2,p)%p;
}
ll lucas(ll n,ll m,ll p){
	if(m==0) return 1;
	return C(n%p,m%p,p)*lucas(n/p,m/p,p);
}
int main(){
	int t=1;
	ll m,n,p;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d%I64d%I64d",&n,&m,&p);
		printf("%I64d\n",lucas(n,m,10000007));
	}
	return 0;
}
