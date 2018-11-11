//M个人，一开始每人收到n个卡牌，每张上有数字最大为N*M，没有一个完全相同
//谁出牌最大赢得本轮比赛
//N轮之后，谁分数最多获胜
//计算赢得的最大轮数 
//m,n  人数，牌数
//n个数
//空行 
//0，0结束
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int m , n , Case = 0 ;
    int a[1005];
    while(cin>>m>>n,m||n){
        Case++;
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        sort(a,a+n);      //从小到大排序 
        int win = 0 , lose = 0 ;
        int max = n*m ;   //存储牌中最大的牌 
        for(int i = n - 1 ; win+lose != n ; i-- ){ //win+lose==n 表示手上的牌已经出完 
            if(max==a[i]){
                win++;    //牌中最大的牌==手上最大的牌时,必赢一次 
                max--;       //赢了,牌中最大的牌值只要减一即可 
            } 
            else{         //否则,必输一次。 
                lose++;   //记录输的次数 
                max-=2;   //输了,牌中最大的牌值减二
            } 
        }
        cout<<"Case "<<Case<<": "<<win<<endl;
    }
    return 0;
}
