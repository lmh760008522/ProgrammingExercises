/*
�ھ���õ� "Mystery Award" 
����Ϊ�������˵õ�  the Minions 
�����˵õ�   chocolates.
����������� �Լ� �����ߵ�id�������ҳ���Ҷ���ʲô�� 
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
	int n; // <=10000 ����������
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
