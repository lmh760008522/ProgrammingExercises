#include<stdio.h>
int a[1001];

void dabiao(){
	a[1] = 1;
	a[2] = 2;
	for(int i=3;i<=1000;i++){
		a[i] = a[i-1] + a[i-2];
	}
}

int main(){
	dabiao();
	int x;
	scanf("%d", &x);
	printf("%d\n", a[x]);
	return 0;
}

/*
这是一个典型的斐波拉契数列。
然而，斐波拉契数列值的增长速度太快了，需要构筑一个大整数类来解决。

 
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
// 无符号整数类，整数放在字符串中，可以用整数初始化。只有加运算功能。
class UBigInt {
private:
    string num;
public:
    UBigInt();
    UBigInt(int n);
    void setNumber(string s);
    const string& getNumber(); // retrieves the number
    UBigInt operator + (UBigInt b);
private:
    string add(string number1, string number2);
};
 
UBigInt::UBigInt() { // empty constructor initializes zero
    num = "0";
}
 
UBigInt::UBigInt(int n) {
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    setNumber(s);
}
 
void UBigInt::setNumber(string s) {
    num = s;
}
 
const string& UBigInt::getNumber() { // retrieves the number
    return num;
}
 
UBigInt UBigInt::operator + (UBigInt b) {
    UBigInt addition;
    addition.setNumber( add(getNumber(), b.getNumber() ) );
 
    return addition;
}
 
string UBigInt::add(string number1, string number2) {
    string add = (number1.length() > number2.length()) ?  number1 : number2;
 
    int diffLength = abs( (int) (number1.size() - number2.size()) );
    if(number1.size() > number2.size())
        number2.insert(0, diffLength, '0'); // put zeros from left
    else// if(number1.size() < number2.size())
        number1.insert(0, diffLength, '0');
 
    char carry = 0;
    for(int i=number1.size()-1; i>=0; --i) {
        add[i] = (carry+(number1[i]-'0')+(number2[i]-'0')) + '0';
 
        if(i != 0) {
            if(add[i] > '9') {
                add[i] -= 10;
                carry = 1;
            } else
                carry = 0;
        }
    }
    if(add[0] > '9') {
        add[0]-= 10;
        add.insert(0,1,'1');
    }
    return add;
}
 
void fib(int n)
{
    if(n == 1) {
        cout << 1 << endl;
    } else if(n == 2) {
        cout << 2 << endl;
    } else {
         UBigInt f1 = 1;
         UBigInt f2 = 2;
         UBigInt temp;
         n -= 2;
         while(n--) {
             temp = f2;
             f2 = f1 + f2;
             f1 = temp;
         }
         cout << f2.getNumber() << endl;
    }
}
 
int main(void)
{
    int n;
 
    while(scanf("%d", &n) != EOF) {
        fib(n);
    }
 
    return 0;
}

*/
