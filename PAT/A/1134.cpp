/*
vertex cover ���㸲�ǣ�һ�鶥�㣬ʹ��ͼ��ÿ������ü��ϵ�����һ�������������
indices: index �ĸ��� 
*/ 
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	map<int, bool> mp;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a, &b);
		mp[a] = false;
	}
	int k;
	scanf("%d", &k);
	bool table[10005];
	for(int i=0;i<k;i++){
		int nv;
		scanf("%d",&nv);
		int num = 0;
		for(int j=0;j<nv;j++){
			int x;
			scanf("%d", &x);
			if(table[x] == false){
				table[x] = true;
				num ++;
			}
		}
		if(num == n){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
} 
