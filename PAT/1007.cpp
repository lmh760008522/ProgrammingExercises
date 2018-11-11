#include<stdio.h>
#include<cmath> 
#include<iostream>
using namespace std;

//部分正确  WHY？？ 
bool judge_prime(int n){
	int i;
	for(i=3;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int count=0,i; 
	long int n;
	cin>>n;
	if((n>=1)&&(n<=4)){
		cout<<count;
		return 0;
	}

	for(i=3;i<=n;i=i+2){
		if(judge_prime(i)&&judge_prime(i+2)){
			count++;
		}
	}
	cout<<count;
	return 0;
} 


/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int pri[100110] = {0};

int prime(int a) {
	if(a % 2 == 0 && a != 2) {
		return 0;
	}
	for(int i = 3; i * i <= a; i++) {
		if(a % i == 0) {
			return 0;
		}
	}
	return a != 1;
}

int main() {
	int n;
	int sum = 0, sub = 0;
	cin >> n;
	for (int i = 2; i <= 100010; i++) {	//一次性筛选出最大范围内的所有素数 
		if(prime(i)) {
			pri[sub++] = i;
		}
	}
	for(int i = 1; pri[i] <= n; i++) {	//求出n以内的素数对的对数 
		if(pri[i] - pri[i - 1] == 2) {
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
*/
