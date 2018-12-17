/*
����ÿ���ڵ��ֵ���ǲ�ͬ����������
��������������������Ψһ��ȷ��һ������
֪�� �������������������ȴ����Ҵ�ӡһ��Ľڵ㣬�ٴ��ҵ�����ӡһ��Ľڵ� 
*/
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

typedef struct node{
	int root;
	int inp, inq, postp, postq, l;	
	int val;
}node;

int n;
vector<int> in;
vector<int> post;
vector<int> level;
map<int, int> lNum;
queue<node> qu;

//�ݹ�ת���� 
/*
void ChangePreorder(int inp, int inq, int postp, int postq, int l){
	if(inp > inq || postp > postq){
		return;
	}
	int root = inp;
	while( in[root] != post[postq] && root <= inq){ //�������һ��ֵ�Ǹ���ֵ 
		root++;
	}
	//�ҵ���,���뵽��α��������� 
	level.push_back(in[root]);
	//ͳ��ÿ�㼸���ڵ� 
	lNum[l]++;
	//�ݹ鿴��������
	ChangePreorder(inp, root-1, postp, root-1, l+1); //������ 
	ChangePreorder(root+1, inq, root, postq-1, l+1); //������ 
}*/ 

//�ݹ�ת��� 
void ChangeLevelorder(){
	node temp;
	temp.val = post[n-1]; 
	temp.inp = 0; temp.inq = n-1; temp.postp = 0; temp.postq = n-1;
	temp.l = 0;
	int root = temp.inp;
	level.push_back(post[n-1]);
	lNum[temp.l]++;
	while(in[root] != post[n-1]) root++;
	temp.root = root;
	qu.push(temp);
	while(qu.size() != 0){
		temp = qu.front();
		qu.pop();
		//������ 
		for(int p = temp.inp; p < temp.root; p++){
			if(in[p] == post[temp.postq-(temp.inq-temp.root)-1]){
				node tt;
				tt.l = temp.l + 1;
				tt.val = in[p];
				tt.inp = temp.inp; tt.inq = temp.root-1; tt.postp = temp.postp; tt.postq = temp.postq-(temp.inq-temp.root)-1;	
				tt.root = p;
				qu.push(tt);
				level.push_back(in[p]);
				lNum[tt.l]++;
			}
		}
		//���Һ��� 
		for(int p = temp.root+1; p <= temp.inq; p++){
			if(in[p] == post[temp.postq-1]){
				node tt;
				tt.l = temp.l + 1;
				tt.val = in[p];
				tt.inp = temp.root+1; tt.inq = temp.inq; tt.postp = temp.root; tt.postq = temp.postq-1;	
				tt.root = p;
				qu.push(tt);
				level.push_back(in[p]);
				lNum[tt.l]++;
			}
		}
	}
}

int main(){
	cin>>n;
	
	in.resize(n);
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	post.resize(n);
	for(int i=0;i<n;i++){
		cin>>post[i];
	}

	ChangeLevelorder();
	/* 
	for(int i=0; i<n;i++){
		cout<<level[i]<<" ";
	}
	cout<<endl;
	*/ 
	
	cout<<level[0];//������ڵ� 
	int p = 1;
	map<int, int>::iterator iter = lNum.begin();//���������ڵ�0�� 
	//�ӵ�һ�㿪ʼ������� 
	for(iter++; iter != lNum.end(); iter++){
		//cout<<iter->first<<" "<<iter->second<<endl; 
		if(iter->first % 2 ==1){//����������ұ��� 
			for(int q = p; q < p+iter->second; q++){
				cout<<" "<<level[q];
			} 
		}else{//ż������ҵ������
			for(int q = p+iter->second-1; q >= p; q--){
				cout<<" "<<level[q];
			} 
		}
		p += iter->second;
		//cout<<endl;
	}
	return 0;
} 
