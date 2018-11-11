#include<cstdio>
#include<vector>
#include<string.h>
#include<iostream>
using namespace std;

typedef struct pair0{
	char n;
	int num;
}pair0;

int main(){
	char s[1005];
	gets(s);
	vector<pair0> v;
	int count=1;
	char te=s[0];
	for(int i = 1; i < strlen(s); i++){
		if(s[i-1] != s[i] && s[i-1]+32 != s[i] &&  s[i-1]-32 != s[i]){
			pair0 temp;
			temp.n = te;
			temp.num = count;
			v.push_back(temp);
			count=1;
			te=s[i];
		}else{
			count++;
		}
	}
	for(int i=0;i<v.size();i++){
		if(v[i].n<72){
			v[i].n+=32;
		}
		cout<<"("<<v[i].n<<","<<v[i].num<<")";
	}
	return 0;
}
