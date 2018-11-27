//Palindrome 回文
//standard notation 标准符号
//iteration 迭代 

#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string plus0(string a, string b){
	int c = 0;
	string ans;
	for(int i = a.length()-1;i>=0;i--){
		char temp = c + a[i] + b[i] - '0';
		if(temp > '9'){
			temp -= 10;
			c = 1;
		}else{
			c = 0;
		}
		ans += temp;
	}
	if(c == 1){
		ans += '1';
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

bool judge(string s){
	for(int i = 0, j = s.length()-1; i <= j; i++, j--){
		if(s[i]!=s[j]){
			return false;
		}
	}
	return true;
}

int main(){
	int i;
	string s1;
	cin>>s1;
	//别忘了首先判断s1 !!! 有两个测试用例是专门测试这个的！
	if(judge(s1)){ 
		cout<<s1<<" is a palindromic number."<<endl;
		return 0;
	}
	for(i=0;i<10;i++){
		string s2 = s1;
		reverse(s1.begin(), s1.end());
		string s3 = plus0(s1, s2);
		cout<<s2<<" + "<<s1<<" = "<<s3<<endl;
		if( judge(s3) ){
			cout<<s3<<" is a palindromic number."<<endl;
			break;
		}
		s1 = s3;
	} 
	if(i==10){
		printf("Not found in 10 iterations.\n");
	}
	return 0;
} 
