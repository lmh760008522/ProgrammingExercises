#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	int id;
	int st, fi;
}node;

bool f_st(node a, node b){
	return a.st < b.st;
}

bool f_fi(node a, node b){
	if(a.fi < b.fi){
		return true;
	}else if( a.fi == b.fi){
		if(a.id < b.id ){
			return true;
		}else{
			return false;
		}
	}
	return false;
}

int main(){
	int n,k;
	scanf("%d %d", &n, &k);
	
	vector<node> v;
	
	for(int i=0; i<k; i++){
		int w, s, c;
		node temp;
		scanf("%d %d %d", &w, &s, &c);
		temp.id = w-1;
		temp.st = s;
		temp.fi = s+c;
		v.push_back(temp);
	}
		
	queue<node> q_st;
	sort(v.begin(), v.end(), f_st);
	for(int i = 0 ; i<k; i++){
		//printf("%d ",v[i].id);
		q_st.push(v[i]); 
	}
	//printf("\n");
	queue<node> q_fi;
	sort(v.begin(), v.end(), f_fi);
	for(int i= 0 ; i<k; i++){
		//printf("%d ",v[i].id);
		q_fi.push(v[i]); 
	}
	
	int hezi[1000], yaoshi[1000];
	for(int i=0; i<n; i++){
		hezi[i] = yaoshi[i] = i;
	}
	
	priority_queue<int,vector<int>,greater<int> > q_empty;
	while(q_st.empty() == 0){ //若借出去的不为空 
		node t_st = q_st.front(), t_fi = q_fi.front();
		if(t_st.st < t_fi.fi){
			q_empty.push( yaoshi[t_st.id] );
			q_st.pop();      
			hezi[ yaoshi[t_st.id] ] = -1;
			yaoshi[t_st.id] = -1;//被拿出
		}else{//if(t_st.st <= t_fi.fi){
			int t_em = q_empty.top();
			hezi[t_em] = t_fi.id;
			yaoshi[t_fi.id] = t_em;
			q_empty.pop();
			q_fi.pop();
		}
	}
	
	//剩下的全是还的
	while(q_fi.empty() == 0){
		node t_fi = q_fi.front();
		int t_em = q_empty.top();
		hezi[t_em] = t_fi.id;
		yaoshi[t_fi.id] = t_em;
		q_empty.pop();
		q_fi.pop();
	}
	
	for(int i=0; i<n;i++){
		printf("%d ", hezi[i]+1);
	}
	return 0;
} 
