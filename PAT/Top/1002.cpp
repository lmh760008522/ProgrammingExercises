//动态规划  
//try1: 1h 部分正确 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct point{
	int p,l,d;
	point(int p0, int l0, int d0){
		p = p0;
		l = l0;
		d = d0;
	}
}Point;

vector<Point > work;

int cmp(Point a, Point b)
{
    if(a.d!= b.d)
        return a.d < b.d;
    else{
    	if(a.l != b.l){
    		return a.l > b.l;
		}else{
			return a.p > b.p;
		}
	}
        
}

int main(){
	int n, p, l, d;//number profit lasing deadline
	int max=0;//最大收益
	
	scanf("%d",&n);
	while(n>0){
		n--;
		scanf("%d %d %d", &p, &l, &d);
		Point point(p, l, d);
		work.push_back(point); 
	}
	sort(work.begin(), work.end(), cmp);//按照截至日期从小到大排序
	
	for(int i = 0; i < work.size(); i++){
		int begin=0, profit=0;//从第0天开始
		profit+=work[i].p;
		begin+=work[i].l;
		for(int j = i+1; j < work.size();j++) {
			if(begin+work[j].l <= work[j].d){
				begin+=work[j].l;
				profit+=work[j].p;
			}
	    }
	   	if(profit >max){
			max = profit;
		}
	}
	printf("%d",max);
	return 0;
} 



/*

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct sion
{
    int v, c, d;
}a[100];

int cmp(sion a, sion b)
{
    if(a.d!= b.d)
        return a.d < b.d;
    else 
        return a.c < b.c;
}


int dp[55][100000];
int main()
{
    int n;
    int sum ,ma ;
    while(cin >> n)
    {
        sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].v >> a[i].c>> a[i].d;
            sum += a[i].c;
            dp[i][0] = 0;    
        }
        sort(a + 1, a + n + 1, cmp);
        ma = 0;
        dp[0][0] = 0;
        /***背包问题关键算法** 
        for(int i = 1; i <= n; i++ )
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j <= a[i].d)
                {
                    dp[i][j] = max(dp[i-1][j-a[i].c]+a[i].v, dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = a[i].v;
                }
                ma = max(ma, dp[i][j]);
            }
        }
        /***背包问题关键算法** 
        printf("%d\n", ma);
        
    }
}*/
