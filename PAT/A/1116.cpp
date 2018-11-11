#include<iostream>
#include<map>
#include<set>
#include<cmath> 
#include<string>
using namespace std;

map<string,int> m;
set<string> check;
int prime[10001];

bool isprime(int a) {
    if(a <= 1) return false;
    int Sqrt = sqrt((double)a);
    for(int i = 2; i <= Sqrt; i++) {
        if(a % i == 0)
            return false;
    }
    return true;
}

int main(){
	int n;
	cin>>n;
	/*
	//建立素数表
	prime[2]=prime[3]=1;
	for(int i=4;i<=n;i++){
		int j;
		for(j=2;j<=sqrt(i);j++){
			if(i % j ==0){
				break;
			}
		}
		if(j == floor(sqrt(i))+1){
			prime[i]==1;//表示 是素数 
		}
	} */
	for(int i=0;i<n;i++){
		string name;
		cin>>name;
		m[name]=i+1;	
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		string name;
		cin>>name;
		map<string,int>::iterator it=m.find(name);
		if(it == m.end()){
			cout<<name<<": Are you kidding?"<<endl;
			continue;
		}
		if(check.count(name)!=0){
			cout<<name<<": Checked"<<endl;
			continue; 
		}
		check.insert(name);
		if(m[name] == 1){
			cout<<name<<": Mystery Award"<<endl;
		}else if( isprime(m[name]) ){//是素数 
			cout<<name<<": Minion"<<endl;
		}else{
			cout<<name<<": Chocolate"<<endl;
		}
	}
	return 0;
} 
