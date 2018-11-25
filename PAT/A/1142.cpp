// clique��һ��ͼ�ڵ���Ӽ����ڵ�֮�䶼�����ڵ�
// maximal clique���������ӽڵ��clique 
//�����ж���clique, maximal clique ����ʲô������ 
#include<stdio.h>
#include<vector>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int e[205][205] = {0}; 
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	int k;
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		int a;
		scanf("%d", &a);
		vector<int> v(a);
		vector<int> table(n+1);
		for(int j=0;j<a;j++){
			scanf("%d", &v[j]);
			table[v[j]] = 1;
		}
		//�ȿ��Ƿ�����
		bool flag1 = true;
		for(int p=0;p<a && flag1;p++){
			for(int q=p+1;q<a;q++){
				if(e[v[p]][v[q]] == 0){
					flag1 = false;
					break;
				}
			}
		}
		if(flag1 == false){
			printf("Not a Clique\n");
			continue;
		}
		//�ٿ��Ƿ��ܼӽ�ȥ�� 
		bool flag2 = true;
		for(int p=1;p<=n;p++){
			if(table[p]==0){
				int q=0;
				for(;q<a;q++){
					if(e[p][v[q]]==0){
						break;
					}
				}
				if(q==a){
					flag2 = false;
					break;
				}
			}
		}
		if(flag2 == false){
			printf("Not Maximal\n");
			continue;
		}
		printf("Yes\n");
	}
	return 0;
} 
 
