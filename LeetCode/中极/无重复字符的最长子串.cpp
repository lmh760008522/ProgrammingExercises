#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main(){
	//char s[9]="abcabcbb";
	//char s[6]="bbbbb";
	//vector<char> ans;
	char s[7]="pwwkew";
	int num[26];
	int len=0,temp=0;
	memset(num,0,sizeof(num));
	int beg=0;
	for(int i=0;i<strlen(s);i++){
		num[ s[i]-97 ]++;
		if(num[ s[i]-97 ]==1){
			temp++;
			//ans.push_back(s[i]);
			if(len<temp){
				len=temp;
			}
		}else{
			while(num[ s[i]-97 ]>1 && beg<=i){
				num[ s[beg]]--;
				beg++;
			}
			beg++;
			temp=0;
			//ans.clear();
		}
	}
	printf("%d",len);
	return 0;
}
