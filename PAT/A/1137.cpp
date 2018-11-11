#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef struct stu{
	string id;
	int a,b;
	int sum;
	int gp;
}stu;
map<string,int> index;
vector<stu> student;


bool cmp(stu a ,stu b){
	if(a.sum==b.sum){
		return a.id<b.id;
	}
	return a.sum>b.sum;
}
int main(){
	int p,m,n;
	cin>>p>>m>>n;
	student.resize(p);
	int count=0;
	for(int i=0;i<p;i++){
		string s;
		int pp;
		cin>>s>>pp;
		if(pp>=200){
			if(index.count(s)==0){
				index[s]=count;
				student[count].id=s;
				student[count].gp=pp;
				student[count].a=student[count].b=-1;
				student[count].sum=0;
				count++;
			}
		}		
	}
	for(int i=0;i<m;i++){
		string s;
		int mm;
		cin>>s>>mm; 
		map<string,int>::iterator key = index.find(s);
		if(key!=index.end()){
			student[key->second].a=mm;
		} 
	}
	for(int i=0;i<n;i++){
		string s;
		int nn;
		cin>>s>>nn; 
		map<string,int>::iterator key = index.find(s);
		if(key!=index.end()){
			student[key->second].b=nn;
			if(student[key->second].a > student[key->second].b){
				double sum= 0.4*student[key->second].a+0.6*student[key->second].b;
				if(sum-int(sum)>=0.5){
					student[key->second].sum = int(sum) +1;
				}else{
					student[key->second].sum = int(sum);
				}
				
			}else{
				student[key->second].sum = student[key->second].b;
			}
		} 
	}
	
	sort(student.begin(),student.end(),cmp);
	
	for(int i=0;i<count;i++){
		if(student[i].sum>=60){
			cout<<student[i].id<<" "<<student[i].gp<<" "<<student[i].a<<" "<<student[i].b<<" "<<student[i].sum<<endl;
		}	
	}
	return 0;
} 
