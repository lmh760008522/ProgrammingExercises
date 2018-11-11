#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
	vector<int> v;
	char s[1005];
	scanf("%s", s);
	
	int sum = 0;
	bool falg = true;
	int i;
	for(i=0; s[i]!='\0'; i++){
		if(s[i] == '5' && falg){
			continue;
		}
		if(s[i] == '5'){
			v.push_back(sum);
			falg = true;//判读是否连续 
			sum = 0;
			continue;
		}
		sum = sum*10 + s[i] - '0';
		falg = false;
	}
	if(s[i-1]!=5){//以防没有5 
		v.push_back(sum);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		printf("%d ", v[i]);
	}
	return 0;
}
