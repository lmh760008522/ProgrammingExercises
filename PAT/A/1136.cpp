#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int ari;
	cin>>ari;
	for(int i=1;i<=10;i++){
		string aga=to_string(ari);
		int j,k;
		for(j=0,k=aga.length()-1;j<=k;j++,k--){//这段可以优化 
			if(aga[j]!=aga[k]){
				break;
			}
		}
		if(j<k){
			string agb = aga.reverse();
			ari = stoi(aga)+stoi(agb);
			cout<<aga<<" + "<<agb<<" = "<<ari<<endl;
		}else{
			cout<<aga<<" is a palindromic number."
			return 0;
		}
	}
	cout<<"Not found in 10 iterations."<<endl;
	return 0;
} 
