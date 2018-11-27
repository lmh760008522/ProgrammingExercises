/*
给链表重新排列
使得负数在非负数之前
值在[0,k]之间的数排在值大于k的之前 
本身顺序不变 
*/
#include<stdio.h>
#include<vector> 
using namespace std;

typedef struct node{
	int add, next;
	int data;
}node;

int main(){
	int sst, n, k;
	scanf("%d %d %d",&sst, &n, &k);
	vector<node> v(100010);
	for(int i=0;i<n;i++){
		node temp;
		scanf("%d %d %d", &temp.add, &temp.data, &temp.next);
		v[temp.add] = temp;
	}
	vector<node> below0;
	vector<node> belowk;
	vector<node> abovek;
	for( ; sst != -1; sst = v[sst].next){
		if(v[sst].data<0){
			below0.push_back(v[sst]);
		}else if(v[sst].data>k){
			abovek.push_back(v[sst]);
		}else{
			belowk.push_back(v[sst]);
		}
	}
	
	for(int i=0;i<below0.size()-1;i++){
		printf("%05d %d %05d\n", below0[i].add, below0[i].data,below0[i+1].add);
	}
	if(belowk.size()!=0){
		printf("%05d %d %05d\n", below0[below0.size()-1].add, below0[below0.size()-1].data,belowk[0].add);
		
	}else{
		printf("%05d %d -1\n", below0[below0.size()-1].add, below0[below0.size()-1].data);
	}
	
	for(int i=0;i<belowk.size()-1;i++){
		printf("%05d %d %05d\n", belowk[i].add, belowk[i].data,belowk[i+1].add);
	}
	if(abovek.size()!=0){
		printf("%05d %d %05d\n", belowk[belowk.size()-1].add, belowk[belowk.size()-1].data,abovek[0].add);
	}else{
		printf("%05d %d -1\n", belowk[belowk.size()-1].add, belowk[belowk.size()-1].data);
	}
	
	for(int i=0;i<abovek.size()-1;i++){
		printf("%05d %d %05d\n", abovek[i].add, abovek[i].data,abovek[i+1].add);
	}
	printf("%05d %d -1\n", abovek[abovek.size()-1].add, abovek[abovek.size()-1].data);
	
	return 0;
} 
