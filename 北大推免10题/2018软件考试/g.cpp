//��С������
/*
��ĸ���P���Ѹ�·��R
����R�У�
id id ·�ĳ���
 p=0����
 
 ���50�㣬100�� 
*/ 
#include<cstdio> 
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	int a,b;
	int len;
};

bool comp(node a1,node a2){
	if(a1.len<a2.len){
		return true;
	}
	return false;
}

int main(){
	int p,r;
	scanf("%d",&p);
	while(p!=0){
		scanf("%d",&r);
		if(r==0){
			printf("0\n");
			scanf("%d %d",&p,&r);
			continue;
		}
		vector<node> v; 
		v.clear();
		
		for(int i=0;i<r;i++){
			int x,y,length;
			scanf("%d %d %d",&x,&y,&length);
			node temp;
			temp.a=x, temp.b=y, temp.len=length;
			v.push_back(temp);
		}
		sort(v.begin(),v.end(),comp);
		int ans=0;
		bool visit[50]={false};
		for(int i=0;i<v.size();i++){
			if(visit[ v[i].a ] == true && visit[ v[i].b ] == true){
				continue;
			}else{
				ans += v[i].len;
				visit[ v[i].a ] = true;
				visit[ v[i].b ] = true;
			}
		}
		printf("%d\n",ans);
		scanf("%d",&p);
	}
	return 0;
}
