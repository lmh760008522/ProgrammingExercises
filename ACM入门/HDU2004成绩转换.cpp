/* HDU2004 成绩转换 */
//般教科书上，实现成绩转换功能用if语句或switch语句，那是浮云。
//用查表法来实现，可以做到逻辑简单，程序运行速度快，语句简洁。
#include <stdio.h>
 
int main(void)
{
    int score;
    char convert[] = "EEEEEEDCBAA";
 
    while(scanf("%d", &score) != EOF) {
          if(score < 0 || score > 100)
              printf("Score is error!\n");
          else
              printf("%c\n", convert[score/10]);
    }
 
    return 0;
}

