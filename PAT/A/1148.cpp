//22/11/18 15:38 
//假设有2个狼人，至少有一个，但是不是全部 在说谎 ，，那岂不是只有1个在说谎 
//至少有2人慌，也就是说村民也有可能说谎 ,且至少有一个村民在说谎 
//枚举 
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
		v[i].flag =  s[0]=='+' ? false : true;//是狼人就是true 
		v[i].id = s[1] - '0';
	}
	int fake_num = 0;//统计说谎人数 
	int flag = false;
	//选取两个狼人 
	for(int i = 1; i <= n; i++){
		if(flag == false){ 
			for(int j = i+1; j <= n; j++){
				bool judge[105] = {false};
				fake_num = 0;
				judge[i] = judge[j] = true; 
				//先判断两个狼人说话是否符合条件 
				if(v[i].flag != judge[ v[i].id ]) fake_num++;
				if(v[j].flag != judge[ v[j].id ]) fake_num++;
				//printf("fake_num:%d ",fake_num);
				if(fake_num != 1) continue;
				//然后判断村民说话是否符合条件 
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
//22/11/18 16:34 运行时错误
 
