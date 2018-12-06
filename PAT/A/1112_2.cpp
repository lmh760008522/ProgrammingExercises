/*
���ļ��̿��ܻ��������K����ĸ��
����һ���ַ���(��a-z, 0-9 �� '_' ��ɣ�������1000���ַ�)�� 
ָ�����ܻ��˵ļ����Լ�ԭʼ���ַ����� 
*/
#include<iostream>
#include<string>
#include<vector> 
#include<set>
#include<map>
using namespace std;

int main(){
	int k;
	cin>>k;
	string s;
	cin>>s;
	map<char, vector<int> > mp;
	for(int i=0;i<s.length(); ){
		int count = 0;
		while( i+ count < s.length() && s[i] == s[i+count]) count++;
		mp[s[i]].push_back(count);
		i += count;
	}
	
	set<char> wrong; //��¼������ĸ 
	map<char, vector<int> >::iterator iter;
	for(iter = mp.begin(); iter != mp.end(); iter++){
		bool flag = true;
		for(int j=0; j < mp[iter->first].size(); j++){
			if(mp[iter->first][j] % k != 0){ //������һ��ֵ��Ϊk�����Ǵ�� 
				flag = false;
				break;
			}
		}
		if(flag) wrong.insert(iter->first);
	}
	
	set<char> exist; //��¼�������ĸ 
	for(int i = 0;i<s.length();i++){
		if(wrong.find(s[i]) != wrong.end()){ //���Ǵ�����ĸ 
			s.erase(i+1,k-1); //ɾ������k-1��
			if(exist.find(s[i]) == exist.end()){
				cout<<s[i];
				exist.insert(s[i]);
			}
		}
	} 
	cout<<endl<<s;
	return 0;
} 
