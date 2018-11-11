#include<cstdio>
#include<string>
#include<string.h>
#include<iostream>
#include<map>
#include <algorithm>
using namespace std;

int main(){
	char s[505];
	int n;
	scanf("%d\n",&n);
	gets(s);
	int max=1;
	map<string ,int> m;
	for(int i=0;i+n-1<strlen(s);i++){
		string ss="";
		for(int j=0;j<n;j++){
			ss+=s[i+j];
		}
		cout<<ss<<endl;
		//if(m.find(ss) == true){
			m[ss]++;
			if(m[ss]>max){
				max=m[ss];
			}
		//}else{
			m.insert(make_pair(ss,1));
		//}
	}
	if(max==1){
		printf("NO");
	}else{
		printf("%d\n",max);
		map<string,int>::iterator iter = m.begin();
		for( ;iter!=m.end();iter++){
			if( iter->second == max){
				cout<<iter->first<<endl;
			}
		} 
	} 
	return 0;
}
