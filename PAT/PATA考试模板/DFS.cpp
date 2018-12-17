/*
DFS
һ�������������̣������̺͹�Ӧ�̡�ÿ���˶�����Ʒ�ӹ�Ӧ�̽����˿����С�
��һ�� Դ��Ӧ�� ��ʼ�� ÿ���˴�һ����Ӧ��������P�۸�������Ʒ���ԣ�1+r%��*P�ļ۸�������
ֻ����������Թ˿����ۡ�
����ÿ���ڹ�Ӧ���ϵ��ˣ����� Դ��Ӧ�� �⣩ֻ��һ����Ӧ�̡� 
���������Ӧ��������˿��ܵõ�����ͼ۸�
˼·��ת����������ͼ�о���������ٵ�·�� 
*/
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int n; //�ڵ�����Դ�ڵ���Ϊ0�� <=10^5 
double p, r; //Դ��Ӧ���ṩ�ļ۸����۱��� 
vector< vector<int> > v;
int num = 0;
double minprice = 9999999;
	
void dfs(int index, double price){
	if(v[index].size()==0){//˵���������� 
		if(price < minprice){
			minprice = price;
			num = 1;
		}else if(price == minprice){
			num++;
		}
	}
	//cout<<price<<endl;
	for(int i=0;i<v[index].size();i++){
		dfs(v[index][i], price*(1+r)); 
	} 
	return;
}

int main(){
	cin>>n>>p>>r;
	r = r*0.01;
	v.resize(n);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}	
	dfs(0, p);
	cout.setf(ios::fixed);
	cout<<fixed<<setprecision(4)<<minprice<<" "<<num<<endl;
	return 0;
} 
