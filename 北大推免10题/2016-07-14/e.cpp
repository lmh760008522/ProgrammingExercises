#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=4*atan(1.0);
const int MOD=1e9+7;
const double eps=1e-8;
const int N=1e3+5;
char a[1025][2050];
void draw(int x,int y,int n) ///确定三角形上面的那个点
{
    if(n==1)
    {
        a[x][y]=a[x+1][y-1]='/';
        a[x][y+1]=a[x+1][y+2]='\\';
        a[x+1][y]=a[x+1][y+1]='_';
        return ;
    }
    int d=1<<(n-1);
    draw(x,y,n-1);///当前的三角形
    draw(x+d,y-d,n-1);///左下的三角形
    draw(x+d,y+d,n-1);///右下的三角形
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int h=(1<<n);
        int w=(1<<(n+1));
        for(int i=1; i<=h; i++)
            for(int j=1; j<=w; j++)
                a[i][j]=' ';
        draw(1,1<<n,n);///画图
        int k=(1<<n)+1;
        for(int i=1; i<=h; i++,k++)
        {
            a[i][k+1]='\0';
            puts(a[i]+1);
        }
        puts("");
    }
    return 0;
}
