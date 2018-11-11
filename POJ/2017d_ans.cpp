#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// ö�ٵ�һ����ť�Ƿ��µ�����������ɣ�����ָ����һ���������������鶼��ȷ����

int oriLock;
int lock;
int destLock;

inline void SetBit(int& n, int i, int v)
{
	if (v)   // v Ϊ1 
	{
		n |= (1 << i);   // ���� n �ĵ� i λΪ 1;
	}
	else
		n &= ~(1 << i);  // ���� n �ĵ� i λΪ0;
}

inline void  FlipBit(int &n, int i)
{
	n ^= (1 << i);  // �� 1 �����ת���� 0 ��򱣳ֲ���
}

inline int GetBit(int n, int i)
{
	return (n >> i) &	1;  // ���� n �� �� i λ
}


int main()
{
	char line[40];
	destLock = lock = oriLock = 0;
	cin >> line;
	int N = strlen(line);
	for (int i = 0; i < N; ++i)
		SetBit(oriLock, i, line[i] - '0'); // oriLock ����ԭ�ַ������ÿһλ
	cin >> line;
	for (int i = 0; i < N; ++i)
		SetBit(destLock, i, line[i] - '0');
	int minTimes = 1 << 30;
	for (int p = 0; p < 2; ++p)
	{ // p ��������߰�ť, p ����Ϊ0����1
		lock = oriLock;     
		int times = 0;    // ͳ�ƴ���
		int curButton = p;
		for (int i = 0; i < N; ++i)
		{
			if (curButton)
			{
				++times;
				if (i > 0)
					FlipBit(lock, i - 1);
				FlipBit(lock, i);
				if (i < N - 1)
					FlipBit(lock, i + 1);
			}
			if (GetBit(lock, i) != GetBit(destLock, i))
				curButton = 1;
			else
				curButton = 0;
		}
		if (lock == destLock)
			minTimes = min(minTimes, times);
		if (minTimes == 1 << 30)
			cout << " impossible" << endl;
		else
			cout << minTimes << endl;
	}
	return 0;
}
