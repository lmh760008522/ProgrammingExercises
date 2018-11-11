#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 101000
using namespace std;
int n,tot;
ll a[N],g[N];
struct node{
    int l,r;
};
node e[N];
ll gcd(ll m,ll n)
{
    for(ll r=n;r!=0;r=m%n,m=n,n=r);
    return m;
}
int main()
{
    int ac;
    for(scanf("%d",&ac);ac;ac--)
    {
        scanf("%d",&n);tot=0;
        for(int i=1;i<=n;i++) e[i].r=i+1,e[i].l=i-1,scanf("%lld",&g[i]);
        ll ans=0;
        for(int l=1;l<=n;l++)
        {
            for(int i=1;i<=l;i=e[i].r)
            {
                g[i]=gcd(g[i],g[l]);ans=max(ans,g[i]*(ll)(l-i+1));
                if(g[i]==g[e[i].l]) e[e[i].l].r=e[i].r,e[e[i].r].l=e[i].l;
            }
        }
        printf("%lld\n",ans);
    }
}
