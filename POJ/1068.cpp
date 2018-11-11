//1.p序列：当出现匹配括号对时，从该括号对的右括号开始往左数，直到最前面的左括号数量，就是pi的值。
//2.w序列：当出现匹配括号对时，包含在该括号对中的所有右括号数（包括该括号对）,就是wi的值。
//不会做 
#include<iostream>
#include<vector>
using namespace std;
vector<int> p,w;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		p.resize(n+1);
		w.resize(n+1);
		for(int j=1;j<n;j++){
			cin>>p[j];
		} 
		w[1]=1;
		bool flag=false;
		int p=0;
		for(int j=1;j<n+1;j++){
			if(j+1 == p[j]){
				w[j]=1;
				if(!falg){
					falg=true;
					p=j;
				}
			}else if(p[j]==p[j-1]){
				int count=0;
				for(int k=p;k<j;k++){
					if(w[k]==1) count ++;
				}
				
			}
		}
	}
	return 0;
} 
