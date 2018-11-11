#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	vector<char> line;
	cout<<"enter a line of text:\n";
	char next;
	cin.get(next);
	while(next!='\n'){
		line.push_back(next);
		cin.get(next);
	} 
	vector<char>::const_iterator where;
	where=find(line.begin(),line.end(),'e');
	vector<char>::const_iterator p;
	cout<<"before e:\n";
	for(p=line.begin();p!=where;p++){
		cout<<*p;
	}
	cout<<endl;
	cout<<"after:\n";
	for(p=where;p!=line.end();p++){
		cout<<*p;
	}
	return 0;
}
