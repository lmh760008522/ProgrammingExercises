#include<iostream>
#include<string.h>
using namespace std;
int score(char ch)     //��������ַ�ת��������
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
   char card[3];  //�洢��������
   int a[3];
   int sum,player,dealer;
    //sumΪ�����Ӯ�����������playerΪ������Ƶĵ���
     while(cin>>deck,deck)
   {
      int count[14]={0};    //���ڴ洢��Ӧλ�õ��Ƴ��ֵĴ���
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
      if(player == 22 )       //����ҵ������ƶ���A��ʱ������ǵ���11+1�ġ�
         player=12;
      dealer=a[0];
      for(i=2 ;i<= 11 ;i  ++)
      {
         if( ( (dealer+i==22)? 12: dealer+i) <player)  
             //�ж�dealer +i��ֵ�Ƿ����22��������൱�ھ�������A������ȡֵΪ12.���ׯ�����ƺ�С����ң����Ӯ
         {
             if(i==10)sum+=deck*4*4 - count[i];    //�ĸ�10��
             else sum +=deck*4-count[i];   //������ֹ�����Ҫ��ȥ
         }
      }
      printf("%0.3f%%\n\n",(double)sum*100/left);
   }
}
