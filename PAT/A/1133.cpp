#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	string addr,next;
	int data;
}node;

vector<node> vec;

bool cmp(node a,node b){
	return a.data<b.data;
}

int main(){
	int n,k;
	string s;
	int p0,pk,p00;
	cin>>s>>n>>k;
	vec.resize(n);
	bool flag = false;
	for(int i=0;i<n;i++){
		cin>>vec[i].addr>>vec[i].data>>vec[i].next;
		if(!flag && vec[i].data>0 ){//��һ������0���� 
			p0=i;
			p00=i-1;//ǰһ�� 
			flag = true;
		}else if(vec[i].data==k){
			pk=i;
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<"88"<<endl;
		if(vec[i].data>k && i<pk){ //�������i���ܴ���˳�� 
			vec[i].next=vec[pk].addr;
			vec[pk].next=vec[i].addr;
		}
		if(vec[i].data<0 && i>p0){ //�������i���ܴ���˳��
			if(p00>=0){
				vec[p00].next=vec[i].addr;
			}
			vec[i].next=vec[p0].addr;
			p0=i;
			p00=i-1;
		}
	}
	
	sort(vec.begin(),vec.end(),cmp);
	
	for(int i=0;i<n;i++){
		cout<<vec[i].addr<<" "<<vec[i].data<<" "<<vec[i].next<<endl;
	}
	return 0;
}
