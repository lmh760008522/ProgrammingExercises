#include <stdio.h>
 
int main()
{
    for(int a=0;a<=5;++a)
       {
          int b=5-a;
          for(int c=0;c<=9;++c)
          {
            if(a*100+b*10+c+b*100+c*11==532)
                printf("%d %d %d\n",a,b,c );
          }
       }
    for(int a=0;a<=4;++a)
       {
          int b=5-a-1;
          for(int c=0;c<=9;++c)
          {
            if(a*100+b*10+c+b*100+c*11==532)
                printf("%d %d %d\n",a,b,c );
          }
       }
    return 0;
}
