#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int> > v(1); 

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int size = n;
		for(int j=0;j<n;j++){
			v.push_back(v[j]);
			v.back().push_back(i);
			for(int k=0;k<v[j].size();k++){
				printf("%d",v[j][k]);
			}
			printf("\n");
		}
	}
	
	return 0;
}  
/*
���������Ŀ�и�������[1,2,3]��˵���ʼ�ǿռ�����ô��������Ҫ����1�����ڿռ��ϼ�1��Ϊ[1]�����������������Լ�[]��[1]����������������2��������֮ǰ���Ӽ������ϣ�ÿ�����Ӹ�2�����Էֱ�õ�[2]��[1, 2]����ô�������е��Ӽ���Ϊ[], [1], [2], [1, 2]��ͬ����3������ɵ�[3], [1, 3], [2, 3], [1, 2, 3], �ټ���֮ǰ���Ӽ��������е��Ӽ����ˣ��������£�
*/
