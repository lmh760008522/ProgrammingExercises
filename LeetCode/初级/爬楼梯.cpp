#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
int main(){
	int n;
	//f(n)=f(n-1)+f(n-2)
	cin>>n;
	a.resize(n+1);
	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}
	if(n==2){
		cout<<"2"<<endl;
		return 0;
	}
	a[1]=1;
	a[2]=2;
	for(int i=3;i<n+1;i++){
		a[i]=a[i-1]+a[i-2];
	}
	cout<<a[n]<<endl;
	return 0;
} 
