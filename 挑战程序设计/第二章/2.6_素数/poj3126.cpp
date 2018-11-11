//给两个四位数a,b 每次改变a中的一位而且改动之后的必须是素数，问最少改动几次可以到b?(永远达不到b就输出impossible)
//先打一个素数表，然后用queue模拟搜索过程，将搜索的深度放入结构体中，可以更好地输出改动次数。
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 10010;
bool prime[maxn];
bool vis[maxn];
bool isfind;
int cnt;
struct num {
    int c;
    int floor;
};
queue<num> que;
num a,b;
void bfs(void)
{   //1033 8179
    //que:2033 3033 ...0033 1133 1233...1933 1043 1053 ... 1023 1034 ... 1032
    que.push(a);
    while(!que.empty()) {
        //p = 1033
        num p = que.front();
        que.pop();
        if(p.c <= 1000 || !prime[p.c] || vis[p.c]) continue;
        vis[p.c] = true;
        if(p.c == b.c) {
            isfind = true;
            cnt = p.floor;
            return;
        }
        for(int i = 1 ; i < 10 ; i ++) {
            num tmp;
            tmp.c = (p.c+1000*i)%10000;
            tmp.floor = p.floor + 1;
            que.push(tmp);
            tmp.c = (p.c/1000)*1000+(p.c%1000+100*i)%1000;
            que.push(tmp);
            tmp.c = (p.c/100)*100+(p.c%100+10*i)%100;
            que.push(tmp);
            tmp.c = (p.c/10)*10+(p.c%10+i)%10;
            que.push(tmp);
        }
    }
}
int main()
{
    prime[0] = prime[1] = false;
    for(int i = 2 ; i < maxn ; i ++) prime[i] = true;
    for(int i = 2 ; i*i <= maxn ; i ++) {
        if(!prime[i]) continue;
        for(int j = i*2 ; j < maxn ; j += i) {
            prime[j] = false;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--) {
        //初始化
        cnt = 0;
        isfind = false;
        while(!que.empty()) que.pop();
        memset(vis,false,sizeof(vis));
        scanf("%d%d",&a.c,&b.c);
        if(a.c == b.c) {
            printf("0\n");
            continue;
        }
        bfs();
        if(isfind) printf("%d\n",cnt);
        else printf("Impossible\n");
    }
    return 0;
}
/*
#include<iostream>
using namespace std;

typedef class
{
	public:
		int prime;
		int step;
}number;

bool JudgePrime(int digit)
{
	if(digit==2 || digit==3)
		return true;
	else if(digit<=1 || digit%2==0)
		return false;
	else if(digit>3)
	{
		for(int i=3;i*i<=digit;i+=2)
			if(digit%i==0)
				return false;
		return true;
	}
}

int a,b;
bool vist[15000];
number queue[15000];

void BFS(void)
{
	int i;  //temporary
	int head,tail;
	queue[head=tail=0].prime=a;
	queue[tail++].step=0;
	vist[a]=true;

	while(head<tail)
	{
		number x=queue[head++];
		if(x.prime==b)
		{
			cout<<x.step<<endl;
			return;
		}

		int unit=x.prime%10;       //获取x的个位
		int deca=(x.prime/10)%10;  //获取x的十位

		for(i=1;i<=9;i+=2)     //枚举x的个位，保证四位数为奇数（偶数必不是素数）
		{
			int y=(x.prime/10)*10+i;
			if(y!=x.prime && !vist[y] && JudgePrime(y))
			{
				vist[y]=true;
				queue[tail].prime=y;
				queue[tail++].step=x.step+1;
			}
		}
		for(i=0;i<=9;i++)     //枚举x的十位
		{
			int y=(x.prime/100)*100+i*10+unit;
			if(y!=x.prime && !vist[y] && JudgePrime(y))
			{
				vist[y]=true;
				queue[tail].prime=y;
				queue[tail++].step=x.step+1;
			}
		}
		for(i=0;i<=9;i++)     //枚举x的百位
		{
			int y=(x.prime/1000)*1000+i*100+deca*10+unit;
			if(y!=x.prime && !vist[y] && JudgePrime(y))
			{
				vist[y]=true;
				queue[tail].prime=y;
				queue[tail++].step=x.step+1;
			}
		}
		for(i=1;i<=9;i++)     //枚举x的千位,保证四位数，千位最少为1
		{
			int y=x.prime%1000+i*1000;
			if(y!=x.prime && !vist[y] && JudgePrime(y))
			{
				vist[y]=true;
				queue[tail].prime=y;
				queue[tail++].step=x.step+1;
			}
		}

	}

	cout<<"Impossible"<<endl;
	return;
}

int main(void)
{
	int test;
	cin>>test;
	while(test--)
	{
		cin>>a>>b;
		memset(vist,false,sizeof(vist));
		BFS();
	}
	return 0;
}
*/ 
