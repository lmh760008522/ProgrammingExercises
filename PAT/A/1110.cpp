//段错误 
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue> 
#include<string.h>
using namespace std;
typedef struct node{
	int id;//这个是多余的 
	int lchild,rchild;
}node; 

int main(){
	int n;
	bool flag = true;
	int root;
	cin>>n;
	vector<node> v(n);
	vector<int> visit(n);
	//memset(visit,0,sizeof(visit));
	for(int i=0;i<n;i++){
		v[i].id = i;
		char a,b;
		if(a=='-'||b=='-'){
			if(a != b){
				flag = false;
				if(a=='-'){
					v[i].lchild = -1;
					v[i].rchild = b-'0';
				}else{
					v[i].lchild = a-'0';
					v[i].rchild = -1;
				}
			}else{
				v[i].lchild = v[i].rchild = -1;
			}
		}else{
			v[i].lchild=a-'0';
			v[i].rchild=b-'0';
		}
		if(v[i].lchild!=-1){
			visit[v[i].lchild]=1;
		}
		if(v[i].rchild!=-1){
			visit[v[i].rchild]=1;
		}
	}
	
	for(int i=0;i<n;i++){//找到根节点 
		if(visit[i]==0){
			root = i;		
		}
	}
	
	queue<int> q;
    q.push(root);
    int cnt = 0;
    int lastnode = 0;
    while(!q.empty()) {
        int index = q.front();
        q.pop();
        if(index != -1) {
            lastnode = index;
            cnt++;
        }else {
            if(cnt != n)
                flag = false;
            break;
        }
        q.push(v[index].lchild);
        q.push(v[index].rchild);
    }
	
	if(flag == false){
		printf("NO %d",root);
	}else{
		printf("YES %d",lastnode);
	}
	return 0;
}
