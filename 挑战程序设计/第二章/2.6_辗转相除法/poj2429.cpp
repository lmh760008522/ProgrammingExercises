//poj 2429 GCD & LCM Inverse ����

/*��Ŀ 
Given two positive integers a and b, we can easily calculate the greatest common divisor (GCD) and the least common multiple (LCM) of a and b. But what about the inverse? That is: given GCD and LCM, finding a and b.
both less than 2^63
a and b in ascending order,output the pair with smallest a + b
*/
/*
���⣺������������ m��n ( m =< n < 2^63)������������� a��b ��ʹ���ǵ����Լ��Ϊ m ,��С������Ϊ n ������ж��飬ȡ a + b ֵ��С����һ�顣
˼·�������⣬���� p = a / m , q = b / m , s = n / m,����GCD(p , q) = 1 ,LCM(p , q) = p * q = s ��
�����Ͻ��ۿ�֪�����������ǰ� s �ֽ��������������˵���ʽ�����ǿ��԰� pollard_rho �� miller_rabin �㷨���Ͻ� s �ֽ����������˵���ʽ������GCD(p , q) = 1�����Զ����ͬ����������ͬʱ�ֵ� p �� q ���ˣ����Ƕ����ͬ����������һ�����崦�������� s �� 2^63 ֮�ڣ����ᳬ��14����ͬ��������ˣ����Կ��Խ���Щ��ö����ˣ��ҵ���ӽ�s��ƽ�����Ҳ����� s ƽ����������Ϊ p ��q = s / p.
���� m = 2, n = 120,�� s = 60 = 2 * 2 * 3 * 5 = 4 * 3 * 5 ,�� 3 ��4 ��5���������������˵õ� 3 , 4 , 5 , 12 , 15 , 20 , 60 �������������s�Ҳ����ڸ���s�ľ��� 5 ���� p =5 , q = s / p = 12 ,���������Ϊ a = p * m = 10 , b = q * m = 24 
*/ 

/*
�򵥽ⷨ��
�ʣ�Ϊʲôa*i+b/i��i���������С��
��i<=sqrt(c)=sqrt(b/a),��f��i��=a*i+b/i�󵼣�f'(i)=a-b/(i*i)
��Ϊi<=sqrt(b/a),����f'(i)<=0
��������iԽ��f(i)ԽС�����������ĺ;�ԽС������ֱ�Ӵ�i�����ֵ��ʼö�٣�һ���������������������a*iҲ�϶��Ǵ���b/i�� 
*/ 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//���Լ��--շת����� ���Ӷ� O��log max(a,b)�� 
long gcd(long a, long b){
	if(b == 0)	return a;
	return gcd(b, a % b);
} 
//��С������ 
long lcm(long a, long b){
	return a/gcd(a, b)*b;
}

int main(){
	long a,b,c,i;
	cin>>a>>b;
	c = b/a;
	for (i = (long)sqrt(c);i>=1;i--){
		if(c%i==0&&gcd(i,c/i)==1){
			cout<<a*i<<" "<<b/i<<endl;
			break; 
		}
	}
	return 0;
}
