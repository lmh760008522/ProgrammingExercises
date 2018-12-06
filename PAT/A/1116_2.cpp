/*
冠军会得到 "Mystery Award" 
排名为素数的人得到  the Minions 
其他人得到   chocolates.
给你比赛排名 以及 参赛者的id，请你找出大家都的什么奖 
*/ 
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<iomanip>
using namespace std;

bool isprime(int num){
	if(num == 2 || num == 3){
		return true;
	}
	for(int i = 2; i*i <= num; i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n; // <=10000 参赛者数量
	cin>>n;
	map<int, int> mp;
	string award[4] = {"Are you kidding?", "Mystery Award", "Minion", "Chocolate"};
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i == 1){
			mp[x] = 1;
		}else if(isprime(i)){
			mp[x] = 2;
		}else{
			mp[x] = 3;
		}
	} 
	int k;
	cin>>k;
	set<int> name;
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		if(mp[x] != 0){
			if(name.find(x) == name.end()){
				cout<<setw(4)<<setfill('0')<<x<<": "<<award[mp[x]]<<endl;
				name.insert(x);
			}else{
				cout<<setw(4)<<setfill('0')<<x<<": Checked"<<endl;
			}
		}else{
			cout<<setw(4)<<setfill('0')<<x<<": "<<award[mp[x]]<<endl;
		}
	}
	return 0;
} 
