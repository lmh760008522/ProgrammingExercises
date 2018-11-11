#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
map <int, bool> vis;
int n, k;

struct POINT
{
    int num, step;
};

bool judge(int x)
{
    if(x == 1 || x % 2 == 0)
        return false;
    for(int i = 3; i <= (int) sqrt(x); i += 2)
        if(x % i == 0)
            return false;
    return true;
}

int BFS()
{
    vis.clear();
    vis[n] = true;
    queue <POINT> q;
    POINT st;
    st.num = n;
    st.step = 0;
    q.push(st);
    while(!q.empty())
    {
        POINT cur, t;
        cur = q.front();
        q.pop();
        if(judge(cur.num))
            return cur.step;
        t.num = cur.num + 1;
        if(!vis[t.num])
        {
            vis[t.num] = true;
            t.step = cur.step + 1;
            q.push(t);
        }
        t.num = cur.num - 1;
        if(!vis[t.num])
        {
            vis[t.num] = true;
            t.step = cur.step + 1;
            q.push(t);
        }
        t.num = cur.num * 2;
        if(!vis[t.num])
        {
            vis[t.num] = true;
            t.step = cur.step + 1;
            q.push(t);
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &n, &k);
        int ans = BFS();
        if(ans <= k)
            printf("BJ gets the pretty meizi with %d minutes!\n", ans);
        else
            printf("Poor BJ, single all his life!\n");
    }
}
