/*
排队。逻辑题 
N个人，k队。
排队规则：
1、每列有n/k个人（向下取整），多余的人站最后一列
2、后排的人数必须>=前排的人数
3、 最高的人站在（m/2+1）的位置
4、其他人先矮后高又矮。假设左相对于右高
5、同样的高度，根据姓名的字母表排序，姓名没有重复 
见到这种很复杂的输入，又有排序。必定用vector的sort,参数多就定义结构体。 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	string name;
	int height;
}node;

bool cmp(node a, node b){
	if(a.height == b.height){
		return a.name > b.name;
	}
	return a.height < b.height;
}

int main(){
	int n ,k;
	cin>>n>>k; 
	vector<node> v;
	for(int i=0;i<n;i++){
		string n;
		int h;
		cin>>n>>h;
		node temp;
		temp.name = n;
		temp.height = h;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	
	int m = n / k; //每排几个人 
	int y = n % k; //余数 
	int count = n-1;
	int hang = 0;
	
	vector< vector<string> > ans(k+1);
	
	vector<string> temp(m+y);  //最后一排 
	int p,q;
	temp[(m+y)/2] = v[count--].name;
	for(p = (m+y)/2-1, q = (m+y)/2+1; p>=0 && q<m+y; p--, q++){
		temp[p] = v[count--].name;
		temp[q] = v[count--].name;	
	} 
	if(p==0){
		temp[p] = v[count--].name;
	}
	for(int j=0;j<m+y;j++){
		ans[hang].push_back(temp[j]);
	}
	hang++;
	
	for(int i=0;i<k-1;i++){//前k-1排，没排m个人。
		vector<string> temp(m); 
		int p,q;
		temp[(m)/2] = v[count--].name;
		for(p = (m)/2-1, q = (m)/2+1; p>=0 && q<m; p--, q++){
			temp[p] = v[count--].name;
			temp[q] = v[count--].name;	
		} 
		if(p==0){
			temp[p] = v[count--].name;
		}
		for(int j=0;j<m;j++){
			ans[hang].push_back(temp[j]);
		}
		hang++;
	}
	
	for(int i = 0; i < hang; i++){
		for(int j = 0; j<ans[i].size();j++){
			if(j!=0){
				cout<<" ";
			}
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
} 
