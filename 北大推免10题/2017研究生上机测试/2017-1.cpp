#include<iostream>
#include<string.h>
using namespace std;
int score(char ch)     //将输入的字符转换成整型
{
   if(ch=='A')
      return 11;
   else if(ch =='T' || ch=='J'||ch=='Q'||ch=='K')
      return 10;
   else
      return ch-'0';
}

int main()
{
   int deck,i;
   char card[3];  //存储输入数据
   int a[3];
   int sum,player,dealer;
    //sum为玩家能赢的所有情况，player为玩家手牌的点数
     while(cin>>deck,deck)
   {
      int count[14]={0};    //用于存储对应位置的牌出现的次数
      memset(a,0,3);
      double left =deck*52- 3;
      sum = player = dealer = 0;       
      for(i=0 ;i< 3;i ++)
      {
         cin>>card[i];
         a[i]=score(card[i]);
         count[a[i]]++;
      }
      player = a[1]+a[2];
      if(player == 22 )       //当玩家的两个牌都是A的时候，相加是等于11+1的。
         player=12;
      dealer=a[0];
      for(i=2 ;i<= 11 ;i  ++)
      {
         if( ( (dealer+i==22)? 12: dealer+i) <player)  
             //判断dealer +i的值是否等于22，如果是相当于就是两个A，所以取值为12.如果庄家手牌和小于玩家，玩家赢
         {
             if(i==10)sum+=deck*4*4 - count[i];    //四个10。
             else sum +=deck*4-count[i];   //如果出现过，就要减去
         }
      }
      printf("%0.3f%%\n\n",(double)sum*100/left);
   }
}
