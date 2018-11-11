#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
typedef struct node{
	char name[8];
	int height;
}node;

bool cmp(node a,node b){
	if(a.height != b.height){
		return a.height>b.height;
	} else{
		return a.name<b.name;
	}
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	node *stu = new node[n];
	int i,j;
	for(i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].height;
	}
	
	sort(stu, stu+n, cmp);
	int step=0; 
	
	for(int row=1; row <=n/k; row++){
		int num = n/k;
		if(row == 1){	
			num += n-num*k;
		}
		//printf("row=%d num=%d:",row,num);
		vector<string> v(num);
		for(j=num/2,i=j-1;i>=0||j<num;i--,j++){
			if(j<num){
				v[j]=stu[step++].name;
			}
			if(i>=0){
				v[i]=stu[step++].name;
			}
		}
		for(i=0;i<num;i++){
			cout<<v[i];
			if(i!=n-1){
				printf(" ");
			}
		}
		cout<<endl; 
	}
	return 0;
}
