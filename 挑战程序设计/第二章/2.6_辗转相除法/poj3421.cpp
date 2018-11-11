/*
�������������������x����x��������ɵ���������ǰһ���������һ������е���󳤶ȣ��Լ����в�ͬ���еĸ�����
���������
����Ҫ��x�������ӷֽ⡣�������Եõ��ܵ����Ӹ���c����ͬ������Ϊf1,f2,...,fn��η����ֱ�Ϊe1,e2,...,en����ô����ͬ���еĸ���Ϊc��/(e1!e2!......en!)��
����˵����
����factorial[]����factorial[i]=k��k=i!����ÿ��Ԫ�ش�����±�Ľ׳�ֵ����ʼ�����׳��������������ظ����㡣
�Ǹ�����Nȡ22��ӦΪ22!���ܹ��洢��unsigned long long���ͱ����У��ٴ���Ѿ��޷��洢�ˡ�
����fcount�洢x���ӵ�����������ecount�洢�������ӵĴη������ظ���������
*/
/*
��x�����������ֽ⣬X-factor Chains�У�����һ����Ϊ1�����Բ��ƣ���i����ǽ��������������к�ǰi��Ļ�������lengthΪ�������ĸ�����numbeuΪ������ȫ���е���������ͬ������֮�������Ҫȥ�ء�
*/
#include <iostream>
using namespace std;
typedef unsigned long long ULL;

const int N = 22;
ULL factorial[N+1] = {1};

void init(int n)
{
    for(int i=1; i<=n; i++)
        factorial[i] = factorial[i - 1] * i;
}

void solve(ULL x)
{
    ULL fcount=0, denominator=1;
    for(ULL i=2; i*i<=x; i++) {
        if(x % i == 0) {
            int ecount = 0;
            while(x % i == 0) {
                ecount++;
                x /= i;
            }
            fcount += ecount;
            denominator *= factorial[ecount];
        }
    }
    if(x > 1)
        fcount += 1;

   cout << fcount << " " << factorial[fcount] / denominator << endl;
}

int main()
{
    init(N);
    ULL x;
    while(cin >> x)
        solve(x);

    return 0;
}
