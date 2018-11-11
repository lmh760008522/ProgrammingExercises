#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	long long N,i,n,M,c,a,b,sum;
	scanf("%lld",&N);
	while(N--)
	{
		scanf("%lld%lld",&M,&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			c=1;
			scanf("%lld%lld",&a,&b);
			while(b)
			{
				if(b&1)
				c=c*a%M;
				
				a=a*a%M;
				b/=2;
			}
			sum=sum+c%M;
		}
		printf("%lld\n",sum%M);
	 }
	return 0;
}
