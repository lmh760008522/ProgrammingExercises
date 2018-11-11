#include<iostream>
using namespace std;
#include<string.h>

int main(){
	int n,grade_min,grade_max,grade;
	char name_min[10],id_min[10],name_max[10],id_max[10],name[10],id[10];
	cin>>n;
	scanf("%s %s %d",name,id,&grade);
	strcpy(name_max,name);
	strcpy(id_max,id);
	grade_max=grade;
	strcpy(name_min,name);
	strcpy(id_min,id);
	grade_min=grade;
	n--;
	//cout<<"此时最小："<<name_min<<' '<<id_min<<endl;
	//cout<<"此时最大："<<name_max<<' '<<id_max<<endl;
	while(n>0){
		scanf("%s %s %d",name,id,&grade);
		if(grade_min>grade){
			strcpy(name_min,name);
			strcpy(id_min,id);	
			grade_min=grade; 
		}
		if(grade_max<grade){
			strcpy(name_max,name);
			strcpy(id_max,id);
			grade_max=grade;
		}
		//cout<<"此时最小："<<name_min<<' '<<id_min<<endl;
	//	cout<<"此时最大："<<name_max<<' '<<id_max<<endl;
		n--;
	}
	cout<<name_max<<' '<<id_max<<endl;
	cout<<name_min<<' '<<id_min<<endl;
	return 0;
}
