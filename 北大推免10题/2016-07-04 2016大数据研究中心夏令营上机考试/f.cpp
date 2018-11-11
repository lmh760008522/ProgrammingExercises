#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct node{
	int val;
	bool flag;
}node;
priority_queue <int, vector<node> > q;
vector< int ,vector<node> > v;



int main()
{
	int t;
	scanf("%d",&t);
	while(t-- >0){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			node temp;
			temp.val=x;
			temp.flag=true;
			q.push(temp);
		}
		while(q.size()!=1){
			node a=q.top();
			q.pop();
			node b=q.top();
			q.pop();
			node c;
			c.val=a.val+b.val;
		}
	}		
} 
