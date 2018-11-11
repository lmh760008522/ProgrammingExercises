/* HDU2005 第几天？ */
 
#include <stdio.h>
 
int leapyear_day(int year, int month)
{
    // 1月或2月不用加１天，其他月份润年加１天，非润年不用加１天
    if(month <= 2)
        return 0;
    else
        return ( ((year%4==0) && (year%100!=0)) || (year%400==0) )?1:0;
}
 
int main(void)
{
    int year, month, day;
    int days;
    int monthsum[] = {  // 到某月份的天数，润年另外加天数
          0                                 // 1月
        , 31                                // 2月
        , 31+28                             // 3月
        , 31+28+31                          // 4月
        , 31+28+31+30                       // 5月
        , 31+28+31+30+31                    // 6月
        , 31+28+31+30+31+30                 // 7月
        , 31+28+31+30+31+30+31              // 8月
        , 31+28+31+30+31+30+31+31           // 9月
        , 31+28+31+30+31+30+31+31+30        // 10月
        , 31+28+31+30+31+30+31+31+30+31     // 11月
        , 31+28+31+30+31+30+31+31+30+31+30  // 12月
    };
 
    while(scanf("%d/%d/%d", &year, &month, &day) != EOF) {
        // 天数　＝　润年需要加的天数（根据年和月计算）　＋　到某月天数 ＋　月内天数
        days = leapyear_day(year, month) + monthsum[month-1] + day;
 
        // 输出结果
        printf("%d\n", days);
    }
 
    return 0;
}

