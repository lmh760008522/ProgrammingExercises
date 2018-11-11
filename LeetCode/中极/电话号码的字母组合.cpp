#include<cstdio>
#include<string>
#include<vector>
using namespace std;
 
string s="234";
vector<char> ans(10,'0');
string cankao="abcdefghijklmnopqrstuvwxyz";
void count(int i){
	if( i == s.length()){
		for(int j=0;j<i;j++){
			printf("%c",ans[j]);
		}
		printf(" ");
		return ;
	}
	ans[i]=cankao[(s[i]-'0'-2)*3];
	count(i+1);
	ans[i]=cankao[(s[i]-'0'-2)*3+1];
	count(i+1);
	ans[i]=cankao[(s[i]-'0'-2)*3+2];
	count(i+1);
	return;
}
int main(){
	
	count(0);
	return 0;
}
