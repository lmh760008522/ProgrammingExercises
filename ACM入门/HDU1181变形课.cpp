#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

vector< vector<int> > a(26);
int visit[26] = {0};
int begin = 'b' - 'a', end = 'm' - 'a';

void find(int start){
	if(start == end){
		printf("YES\n");
		return;
	}
	for(int i=0; i<a[start].size(); i++){
		if(visit[a[start][i]] == 0){
			visit[a[start][i]] = 1;
			find(a[start][i]);
			visit[a[start][i]] = 0;
		}
	}
}

int main(){
	string s;
	while( cin>>s ){
		if( s == "0"){
			break;
		}
		a[ s[0]-'a'].push_back(s[s.length()-1] - 'a');
	}
	find(begin);
	return 0;
} 
