/*
�Ŷӡ��߼��� 
N���ˣ�k�ӡ�
�Ŷӹ���
1��ÿ����n/k���ˣ�����ȡ�������������վ���һ��
2�����ŵ���������>=ǰ�ŵ�����
3�� ��ߵ���վ�ڣ�m/2+1����λ��
4���������Ȱ�����ְ���������������Ҹ�
5��ͬ���ĸ߶ȣ�������������ĸ����������û���ظ� 
�������ֺܸ��ӵ����룬�������򡣱ض���vector��sort,������Ͷ���ṹ�塣 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	string name;
	int height;
}node;

bool cmp(node a, node b){
	if(a.height == b.height){
		return a.name > b.name;
	}
	return a.height < b.height;
}

int main(){
	int n ,k;
	cin>>n>>k; 
	vector<node> v;
	for(int i=0;i<n;i++){
		string n;
		int h;
		cin>>n>>h;
		node temp;
		temp.name = n;
		temp.height = h;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	
	int m = n / k; //ÿ�ż����� 
	int y = n % k; //���� 
	int count = n-1;
	int hang = 0;
	
	vector< vector<string> > ans(k+1);
	
	vector<string> temp(m+y);  //���һ�� 
	int p,q;
	temp[(m+y)/2] = v[count--].name;
	for(p = (m+y)/2-1, q = (m+y)/2+1; p>=0 && q<m+y; p--, q++){
		temp[p] = v[count--].name;
		temp[q] = v[count--].name;	
	} 
	if(p==0){
		temp[p] = v[count--].name;
	}
	for(int j=0;j<m+y;j++){
		ans[hang].push_back(temp[j]);
	}
	hang++;
	
	for(int i=0;i<k-1;i++){//ǰk-1�ţ�û��m���ˡ�
		vector<string> temp(m); 
		int p,q;
		temp[(m)/2] = v[count--].name;
		for(p = (m)/2-1, q = (m)/2+1; p>=0 && q<m; p--, q++){
			temp[p] = v[count--].name;
			temp[q] = v[count--].name;	
		} 
		if(p==0){
			temp[p] = v[count--].name;
		}
		for(int j=0;j<m;j++){
			ans[hang].push_back(temp[j]);
		}
		hang++;
	}
	
	for(int i = 0; i < hang; i++){
		for(int j = 0; j<ans[i].size();j++){
			if(j!=0){
				cout<<" ";
			}
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
} 
