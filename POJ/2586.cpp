#include <iostream>

using namespace std;

int main()
{
    int s, d, dSeason, sum; //dSeason指每五个月亏损最少需要几个d
    int dYear[] = {2, 4, 6, 9, 12}; //每五个月里需要的d造成的年亏损月份数
    while (cin >> s >> d)
    {
        dSeason = 1; //至少亏损一个月
        while ((5-dSeason)*s - dSeason*d > 0) ++dSeason;
        sum = (12-dYear[dSeason-1])*s - dYear[dSeason-1]*d; //年净收入
        if (sum < 0) cout << "Deficit" << endl;
        else cout << sum << endl;
    }
    return 0;
}
