//PAT1003
//����1��2�ǻ���Ҫ��
//����3��aPbTc ==>  aPbATca����ô�������� aPbATca �� aPbTc��ֱ��  a'PATa'   ������ʽ��˵��Դ�ַ����Ƿ���Ҫ���
//��ϸ˵����aPbTc����b��ÿ�μ���һ��A��c�м���a�ַ�����ֱ��cPATd��ʽ����c==d����˵���������2����ԭ������Ҫ��

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
		int p = str.find_first_not_of('A');						//�ҵ���һ������A���ַ���λ��
		if ( p == string::npos || str[p] != 'P' )				//δ�ҵ���pλ�ò���P�򲻷��Ϲ���1
		{
			cout<<"NO"<<endl;
			continue;
		}
		int t = str.find_first_not_of('A', p+1);				//��p+1λ�ü���Ѱ�ҵ�һ������A���ַ�
		if ( t == p+1 || t == string::npos || str[t] != 'T' )	//PT֮��ľ��A�����Ҳ���������T���򲻷��Ϲ���1��2
		{
			cout<<"NO"<<endl;
			continue;
		}
		int end = str.find_first_not_of('A', t+1);				//��t+1λ�ü���Ѱ����һ������A���ַ�
		if ( end != string::npos )								//���ҵ����򲻷��Ϲ���1��2
		{
			cout<<"NO"<<endl;
			continue;
		}
		int a = p;
		int b = t - p - 1;
		int c = str.length() - t - 1;							//���ù���3����ǰ�ݹ�
		c -= ( b - 1 ) * a;
		if ( a == c )											//ͨ������2�ж��Ƿ���ȷ
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
