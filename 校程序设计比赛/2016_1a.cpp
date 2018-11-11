#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const MAX = 100005;
int const INF = 0x3fffffff;
int need[15], has[15];
char s[MAX];

bool judge()
{
    for(int i = 0; i < 10; i++)
        if(has[i] < need[i])
            return false;
    return true;
} 

int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {   
        memset(has, 0, sizeof(has));
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i < 10; i++)
            scanf("%d", &need[i]);
        int st = 0, ed = 0, ans = INF;
        while(ed < len)
        {
            while(!judge() && ed < len)
            {
                has[s[ed] - '0'] ++;
                ed ++;
            }
            while(judge() && st < ed)
            {
                ans = min(ans, ed - st);
                has[s[st] - '0'] --;
                st ++;
            }
        }
        if(ans == INF)
            printf("Let's break up\n");
        else
            printf("%d\n", ans);
    }   
}
