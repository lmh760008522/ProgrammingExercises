//22/11/18 15:38 
//������2�����ˣ�������һ�������ǲ���ȫ�� ��˵�� ����������ֻ��1����˵�� 
//������2�˻ţ�Ҳ����˵����Ҳ�п���˵�� ,��������һ��������˵�� 
//ö�� 
#include<stdio.h>
#include<vector>
using namespace std;

typedef struct node{
	bool flag;
	int id;
}node;
 
int main(){
	int n;
	scanf("%d", &n); 
	vector<node> v(n+1);
	for(int i=1;i<=n;i++){
		char s[2];
		scanf("%s",s);
		v[i].flag =  s[0]=='+' ? false : true;//�����˾���true 
		v[i].id = s[1] - '0';
	}
	int fake_num = 0;//ͳ��˵������ 
	int flag = false;
	//ѡȡ�������� 
	for(int i = 1; i <= n; i++){
		if(flag == false){ 
			for(int j = i+1; j <= n; j++){
				bool judge[105] = {false};
				fake_num = 0;
				judge[i] = judge[j] = true; 
				//���ж���������˵���Ƿ�������� 
				if(v[i].flag != judge[ v[i].id ]) fake_num++;
				if(v[j].flag != judge[ v[j].id ]) fake_num++;
				//printf("fake_num:%d ",fake_num);
				if(fake_num != 1) continue;
				//Ȼ���жϴ���˵���Ƿ�������� 
				for(int k = 1; k <= n; k++){
					if(k != i && k != j){
						if(v[k].flag != judge[ v[k].id ]) fake_num++;
					} 
				}
				//printf(" %d\n",fake_num);
				if(fake_num == 2){
					printf("%d %d", i, j);
					flag = true;
					break;
				}
			}
		}else{
			break; 
		} 
	}
	if(flag == false){
		printf("No Solution\n");
	}
	return 0;
}
//22/11/18 16:34 ����ʱ����
 
