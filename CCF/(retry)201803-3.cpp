//��СдӢ����ĸ�����������֡����� -���»��� _ ��С���� 
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct url{
	string id;
	string path[20];	
}url;

int main(){
	int n, m;
	scanf("%d %d",&n, &m);
	
	vector<url> u;
	for(int i=0;i<n;i++){
		string pi, ri;//��������
		cin>>pi;
		cin>>ri;
		
		url temp;
		temp.id = ri;
		int k=0;
		for(int j=0, p=1; p<pi.length(); ){
			while(pi[p]!='\\'){
				p++;
			}
			temp.path[k] = pi.substr(j+1,p-1);
			k++;
			j=p;
			p++;
		}
		u.push_back(temp);
	}
	
	for(int j=0;j<m;j++){
		string qi;
		cin>>qi;
		
		for(int k=0;k<n;k++){
			
		}
	}
	
	
	return 0;
} 
