/* HDU2004 �ɼ�ת�� */
//��̿����ϣ�ʵ�ֳɼ�ת��������if����switch��䣬���Ǹ��ơ�
//�ò����ʵ�֣����������߼��򵥣����������ٶȿ죬����ࡣ
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

