/*
�����������ºͲμ��ɶԵ��ˣ��ҳ��μ��ɶԵ�����Щ�ǵ���
(���±��������˶����ſ���) 
��int���0��00000���������Ի�����string�� 
*/
#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<set>
#include<string> 
using namespace std;
int main(){
	int n; //n<=50000,��������
	cin>>n;
	map<string ,string> coupleList;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		coupleList[a] = b;
		coupleList[b] = a;
	} 
	int m; //<=10000,�μ��ɶԵ�����
	cin>>m; 
	set<string> option;
	vector<string> ans; 
	for(int i=0;i<m;i++){
		string x;
		cin>>x;
		if(coupleList[x] == ""){//�������� 
			ans.push_back(x);
		}else{
			option.insert(x);
		}
	} 
	set<string>::iterator iter;
	for(iter = option.begin(); iter != option.end(); iter++){
		if(option.find(coupleList[*iter]) == option.end()){//���Ҳ��� 
			ans.push_back(*iter);
		}
	}
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		if( i != 0){
			cout<<" ";
		}
		cout<<ans[i];
	}
	return 0;
}
