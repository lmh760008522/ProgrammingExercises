#include <iostream>
#include <cmath>
using namespace std;
const int N=3000;
char b[N+10][N+10];
int main()
{
    int n,q,dsize;//dsize边长
    char a[6][6];
    while(cin>>n&&n!=0)
    {
        cin.get();
        for(int i=0;i<n;i++)
            cin.getline(a[i],10);
        cin>>q;
        //开始计算
        dsize=pow(n,q);

        int t1,t2,m1,m2,tmp,j;/*遍历每一个点*/
        for(int x=0;x<dsize;x++)
        {
            for(int y=0;y<dsize;y++)
            {
                t1=x;
                t2=y;
                j=q;
                while(--j)
                {
                    tmp=pow(n,j);
                    m1=t1/pow(n,j);//除法是看该位置对应基本块的哪一个位置
                    m2=t2/pow(n,j);
                    if(a[m1][m2]==' ')//对应基本块的该位置为空格，则此处为空格
                    {
                        b[x][y]=' ';
                        break;
                    }
                    t1=t1%tmp;//取余是将大图缩小成小图，最终缩小到基本快中
                    t2=t2%tmp;
                }
                if(!j){b[x][y]=a[t1][t2];}
            }
        }
        for(int x=0;x<dsize;x++)
        {
            for(int y=0;y<dsize;y++)
                cout<<b[x][y];
            cout<<endl;
        }
    }
    return 0;
}
