//1.p���У�������ƥ�����Ŷ�ʱ���Ӹ����ŶԵ������ſ�ʼ��������ֱ����ǰ�������������������pi��ֵ��
//2.w���У�������ƥ�����Ŷ�ʱ�������ڸ����Ŷ��е������������������������Ŷԣ�,����wi��ֵ��
//������ 
#include<iostream>
#include<vector>
using namespace std;
vector<int> p,w;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		p.resize(n+1);
		w.resize(n+1);
		for(int j=1;j<n;j++){
			cin>>p[j];
		} 
		w[1]=1;
		bool flag=false;
		int p=0;
		for(int j=1;j<n+1;j++){
			if(j+1 == p[j]){
				w[j]=1;
				if(!falg){
					falg=true;
					p=j;
				}
			}else if(p[j]==p[j-1]){
				int count=0;
				for(int k=p;k<j;k++){
					if(w[k]==1) count ++;
				}
				
			}
		}
	}
	return 0;
} 
