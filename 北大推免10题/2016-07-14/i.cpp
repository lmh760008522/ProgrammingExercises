#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=1000000;
map<string,int>Map;
int G[40][40];
int n,m,p,val;
void initial_Map()
{
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++)
            G[i][j]=inf;
    }
    Map.clear();
}
void floyd()
{
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T,cas=0;
    string str1,str2;
    scanf("%d",&T);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    while(T--){
        printf("DATA SET %d\n\n",++cas);
        initial_Map();
        scanf("%d%d%d",&n,&m,&p);
        for(int i=0;i<n;i++){
            cin>>str1;
            Map[str1]=i;           //string到int的映射
        }
        while(m--){
            cin>>str1>>str2;
            int u=Map[str1];
            int v=Map[str2];
            G[u][v]=G[v][u]=1; //是无向图
        }
        floyd();
        for(int i=1;i<=p;i++){
            cin>>val>>str1>>str2;
            int st=Map[str1];
            int ed=Map[str2];
            if(G[st][ed]!=inf){
                printf("$%d\n",G[st][ed]*val*100);  //船的大小*leg数（最短路）*100
            }else{
                printf("NO SHIPMENT POSSIBLE\n");
            }
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
