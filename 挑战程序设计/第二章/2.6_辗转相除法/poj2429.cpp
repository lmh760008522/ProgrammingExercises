//poj 2429 GCD & LCM Inverse 数论

/*题目 
Given two positive integers a and b, we can easily calculate the greatest common divisor (GCD) and the least common multiple (LCM) of a and b. But what about the inverse? That is: given GCD and LCM, finding a and b.
both less than 2^63
a and b in ascending order,output the pair with smallest a + b
*/
/*
题意：给出两个整数 m、n ( m =< n < 2^63)，求出两个整数 a、b ，使他们的最大公约数为 m ,最小公倍数为 n ，如果有多组，取 a + b 值最小的那一组。
思路：由题意，则令 p = a / m , q = b / m , s = n / m,则有GCD(p , q) = 1 ,LCM(p , q) = p * q = s 。
由以上结论可知此题是让我们把 s 分解成两个互质数相乘的形式。我们可以把 pollard_rho 和 miller_rabin 算法相结合将 s 分解成素因子相乘的形式，由于GCD(p , q) = 1，所以多个相同的素数不能同时分到 p 和 q 里，因此，我们多个相同的素数当作一个整体处理。又由于 s 在 2^63 之内，不会超过14个不同的素数相乘，所以可以将这些数枚举相乘，找到最接近s的平方根且不大于 s 平方根的数即为 p ，q = s / p.
例如 m = 2, n = 120,则 s = 60 = 2 * 2 * 3 * 5 = 4 * 3 * 5 ,从 3 、4 、5中挑出任意个数相乘得到 3 , 4 , 5 , 12 , 15 , 20 , 60 ，其中最靠近根号s且不大于根号s的就是 5 ，即 p =5 , q = s / p = 12 ,所以最后结果为 a = p * m = 10 , b = q * m = 24 
*/ 

/*
简单解法：
问：为什么a*i+b/i随i的增大而减小？
答：i<=sqrt(c)=sqrt(b/a),设f（i）=a*i+b/i求导：f'(i)=a-b/(i*i)
因为i<=sqrt(b/a),所以f'(i)<=0
所以所以i越大f(i)越小，即两个数的和就越小，所以直接从i的最大值开始枚举，一旦符合条件就输出，另外a*i也肯定是大于b/i的 
*/ 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//最大公约数--辗转相除法 复杂度 O（log max(a,b)） 
long gcd(long a, long b){
	if(b == 0)	return a;
	return gcd(b, a % b);
} 
//最小公倍数 
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
