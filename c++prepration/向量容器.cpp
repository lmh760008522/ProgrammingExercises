#include<vector> 
#include<iostream>
using namespace std;
int main(){
	vector<int> sample(3,5);
	vector<int> intv;
	int temp,i;
	cout<<"enter and press 0 to end"<<endl;
	cin>>temp;
	while(temp!=0){
		intv.push_back(temp);
		cin>>temp;
	}
	cout<<intv.size()<<endl;
	for (i=0;i<3;i++){
		cout<<intv[i]<<" ";
	} 
	cout<<endl;
	for (i=0;i<3;i++){
		cout<<sample[i]<<" ";
	} 
	cout<<endl;
	return 0;
}
