/*
并查集 
已知每个人的家庭成员、名下房产 
求每个家庭的总人数，以及平均拥有房产 
*/
#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<map> 
using namespace std;

typedef struct fam{
	int peoplenum, setnum;
	double areasum;
}fam;

typedef struct per{
	int sn;
	double area;
}per;

int n;
int table[10005]; //并查集 
map<int, per> person;
map<int, fam> family;
bool visit[10005];

int find(int x){
	if(table[x] == x) return x;
	return table[x] = find(table[x]);
}

void unionnum(int a, int b){
	int aa = find(a);
	int bb = find(b);
	//合并的时候编号小的作为父亲节点
	if( a < b){
		table[b] = a;
	}
	if(a > b){
		table[a] = b;
	}
}

int main(){
	cin>>n;
	for(int i=0;i<10005;i++){
		table[i] = i;
	}
	for(int i=0;i<n;i++){
		int id,fa,ma, k;
		cin>>id>>fa>>ma>>k;
		visit[id] = true;
		if(fa != -1){
			unionnum(id,fa);
			visit[fa] = true;
		}
		if(ma != -1){
			unionnum(id,ma);
			visit[ma] = true;
		}
		for(int j=0;j<k;j++){
			int child;
			cin>>child;
			unionnum(id, child);
			visit[child] = true;
		}
		double m,area;
		cin>>m>>area;
		per temp;
		temp.sn = m;
		temp.area = area;
		person[id] = temp;
	}
	
	int numfam = 0;
	for(int i=0;i<10005;i++){
		if(visit[i] == true){
			cout<<i<<" "<<table[i]<<endl;
		}
		if(table[i] == i && visit[i] == true){
			numfam++;
		}
		if(visit[i] == true){
			family[find(table[i])].peoplenum++;
		}
	}
	
	map<int, per>::iterator iter1;
	for(iter1 = person.begin(); iter1 != person.end(); iter1++){
		family[find(iter1->first)].setnum += iter1->second.sn;
		family[find(iter1->first)].areasum += iter1->second.area;
	}
	
	cout<<numfam<<endl;
	map<int, fam>::iterator iter2;
	for(iter2 = family.begin(); iter2 != family.end(); iter2++){
		cout<<iter2->first<<" "<<iter2->second.peoplenum<<endl;
	}
	return 0;
} 
