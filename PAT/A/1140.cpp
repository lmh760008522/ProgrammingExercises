//����˵�ĺܸ��ӡ���ʵ���ǰ���ͳ��ǰһ���ַ���������������ͬ���ַ�
#include<iostream>
#include<string>
using namespace std;

int n;
string d;

void change(string s, int count){
	if(count == n){
		cout<<s<<endl;
		return;
	}
	string temp = "";
	int i, j, num;
	for(i = 0; i < s.length(); i++){
		num = 0;
		temp += s[i];
		for(j=i; j<s.length() ;j++){
			if(s[j]!=s[i]){
				break;
			}else{
				num++;
			}
		}
		i = j-1;
		temp += num + '0';
	}
	change(temp, count+1);
}
int main(){
	cin>>d>>n;
	change(d,1);
	return 0;
} 
