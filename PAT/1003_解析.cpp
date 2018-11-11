//PAT1003
//规则1和2是基本要求
//规则3：aPbTc ==>  aPbATca，那么可以逆推 aPbATca 到 aPbTc，直到  a'PATa'   这种形式，说明源字符串是符合要求的
//详细说明：aPbTc，则b中每次减少一个A，c中减少a字符串，直到cPATd形式，若c==d，则说明满足规则2，即原串符合要求

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while ( n-- )
	{
		string str;
		cin>>str;
		int p = str.find_first_not_of('A');						//找到第一个不是A的字符的位置
		if ( p == string::npos || str[p] != 'P' )				//未找到或p位置不是P则不符合规则1
		{
			cout<<"NO"<<endl;
			continue;
		}
		int t = str.find_first_not_of('A', p+1);				//从p+1位置继续寻找第一个不是A的字符
		if ( t == p+1 || t == string::npos || str[t] != 'T' )	//PT之间木有A，或找不到，或不是T，则不符合规则1或2
		{
			cout<<"NO"<<endl;
			continue;
		}
		int end = str.find_first_not_of('A', t+1);				//从t+1位置继续寻找下一个不是A的字符
		if ( end != string::npos )								//若找到，则不符合规则1或2
		{
			cout<<"NO"<<endl;
			continue;
		}
		int a = p;
		int b = t - p - 1;
		int c = str.length() - t - 1;							//利用规则3，往前递归
		c -= ( b - 1 ) * a;
		if ( a == c )											//通过规则2判断是否正确
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
