#include<iostream>
#include<set>
using namespace std;

int digitsum(int x){
	int tempsum=0;
	while(x>0){
		tempsum+=x%10;
		x=x/10;
	}
	return tempsum;
}
int main(){
	int n;
	cin>>n;
	set<int> v;
	int count=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		int digit=digitsum(a);
		if(!v.count(digit)){
			v.insert(digit);
			count++;
		}
	}
	cout<<count<<endl;
	int j=0;
	for(set<int>::iterator it=v.begin(); it!=v.end();it++,j++){
		cout<<*it;
		if(j!=count-1){
			cout<<" ";
			//j++;
		}else{
			cout<<endl;
		}
	}
	return 0;
}
