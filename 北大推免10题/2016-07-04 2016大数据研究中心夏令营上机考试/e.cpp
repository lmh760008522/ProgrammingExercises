// 背包问题（动态规划）
#include <iostream> 
#include <cstdio>
#include <cstring>
#define MAXN 3402
#define MAXM 12880
using namespace std;

int main(){
    int N, M, W[MAXN+5], D[MAXN+5], dp[MAXM+5];
    while(scanf("%d%d", &N, &M) != EOF){
        for(int i=0; i<N; i++){
            scanf("%d%d", &W[i], &D[i]);
        }
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<N; i++){
            for(int left_w=M; left_w>=W[i]; left_w--){
                dp[left_w] = max(dp[left_w-W[i]]+D[i], dp[left_w]);
            }
        }
        printf("%d\n", dp[M]);
    }
    
    return 0;
}
