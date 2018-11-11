#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 枚举第一个按钮是否按下的两种情况即可，对于指定的一种情况，后面的事情都是确定的

int oriLock;
int lock;
int destLock;

inline void SetBit(int& n, int i, int v)
{
	if (v)   // v 为1 
	{
		n |= (1 << i);   // 设置 n 的第 i 位为 1;
	}
	else
		n &= ~(1 << i);  // 设置 n 的第 i 位为0;
}

inline void  FlipBit(int &n, int i)
{
	n ^= (1 << i);  // 与 1 异或跳转，与 0 异或保持不变
}

inline int GetBit(int n, int i)
{
	return (n >> i) &	1;  // 返回 n 的 第 i 位
}


int main()
{
	char line[40];
	destLock = lock = oriLock = 0;
	cin >> line;
	int N = strlen(line);
	for (int i = 0; i < N; ++i)
		SetBit(oriLock, i, line[i] - '0'); // oriLock 保存原字符数组的每一位
	cin >> line;
	for (int i = 0; i < N; ++i)
		SetBit(destLock, i, line[i] - '0');
	int minTimes = 1 << 30;
	for (int p = 0; p < 2; ++p)
	{ // p 代表最左边按钮, p 可能为0，或1
		lock = oriLock;     
		int times = 0;    // 统计次数
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
