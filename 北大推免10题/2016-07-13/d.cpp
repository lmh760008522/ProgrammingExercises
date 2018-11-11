#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<double> male,female;
	for(int i=0;i<n;i++){
		char s[20];
		double high;
		scanf("%s %lf",&s,&high); 
		if(strcmp(s,"male")==0){
			male.push_back(high);
		}else{
			female.push_back(high);
		}
	}
	sort(male.begin(),male.end());
	sort(female.begin(),female.end());
	printf("%.2lf",male[0]);
	for(int i=1;i<male.size();i++){
		printf(" %.2lf",male[i]);
	}
	for(int i=female.size()-1;i>=0;i--){
		printf(" %.2lf",female[i]);
	}
	return 0;
} 
