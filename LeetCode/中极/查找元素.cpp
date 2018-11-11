#include<cstdio>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main(){
	string s[6]={"eat", "tea", "tan", "ate", "nat", "bat"};
	vector< set<char> > v;
	vector< string > ans;
	//printf("%s",s[1]);
	for(int i=0; i<6;i ++){
		set<char> s;
		for(int j=0; j<s[i].length(); j++){
			s.insert(s[i][j]);
		}
		for(int k=0;k<v.end();k++){
			if(v[k]==s){
				ans[k]+=s[i];
				break;
			}
		}
		if(k==v.end()){
			v[k]=s;
			ans[k]+=s[i];
		}
	}
	return 0;
}
