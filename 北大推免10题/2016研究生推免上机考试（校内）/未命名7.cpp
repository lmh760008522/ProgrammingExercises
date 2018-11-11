#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2220;
int G[N][N];
int low[N],vis[N];
char s[N][10];
int n;
int prim()
{
    memset(vis,0,sizeof(vis));
    int  pos=0;
    int min;
    int ans=0;
    vis[0]=1;
    for(int i=0;i<n;i++)
    low[i]=G[pos][i];
    for(int i=0;i<n-1;i++)
    {
        min=100;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&low[j]<min)
            {
                min=low[j];
                pos=j;
            }
        }
        vis[pos]=1;
        ans+=min;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&low[j]>G[pos][j])
            low[j]=G[pos][j];
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
        scanf("%s",s[i]);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int tmp=0;
                for(int k=0;k<7;k++)
                {
                if(s[i][k]!=s[j][k])
                    tmp++;
                }
                int u=i;
                int v=j;
              G[u][v]=tmp;
              G[v][u]=tmp;
            }
        }
    int ans=prim();
    printf("The highest possible quality is 1/%d.\n",ans);  
    }
    return 0;
}
