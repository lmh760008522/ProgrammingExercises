#include <iostream>

using namespace std;

int main()
{
    int s, d, dSeason, sum; //dSeasonָÿ����¿���������Ҫ����d
    int dYear[] = {2, 4, 6, 9, 12}; //ÿ���������Ҫ��d��ɵ�������·���
    while (cin >> s >> d)
    {
        dSeason = 1; //���ٿ���һ����
        while ((5-dSeason)*s - dSeason*d > 0) ++dSeason;
        sum = (12-dYear[dSeason-1])*s - dYear[dSeason-1]*d; //�꾻����
        if (sum < 0) cout << "Deficit" << endl;
        else cout << sum << endl;
    }
    return 0;
}
