/*
字符串 
这题搞了绝壁1小时了 
real numbers：实数 
accurate up to：精确到 
2 decimal places：两位小数 
给N个实数 ，计算符合条件的数的平均值。
符合条件的数是范围在[-1000,1000]的数字，并且精确到两位小数 。 
*/
//案例三错误 :题意不清，题目中说1个是number不是numbers 
/*
 scanf("%s", a);
 sscanf(a, "%lf", &temp);
 sprintf(b, "%.2lf",temp);
*/
 
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	int n; // n<=100
	cin>>n;
	int count = 0;
	double sum = 0.0;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		bool flag = true;
		bool exist = false;
		double num = 0.0;
		double k = 1;
		bool fuhao = true, ex_fu = false;
		for(int j=0;j<s.length();j++){
			if( (s[j]== '+' || s[j] == '-') && ex_fu == false){
				ex_fu = true;
				if(s[j]== '-'){
					fuhao = false;
				}
			}else if( (s[j]== '+' || s[j] == '-') && ex_fu == true){
				flag = false;
				break;
			}else if(((!(s[j]>='0' && s[j]<='9')) && s[j]!='.') || (s[j] == '.' && exist == true)){
				flag = false;
				break;
			}else if(s[j] == '.' && exist == false && j != 0){
				exist = true;
			}else if(s[j] == '.' && exist == false && j == 0){// .2是不正确的 
				flag = false;
				break;
			}else{
				if(exist == false){
					num = num*10 + s[j] - '0';
				}else{
					k = k*0.1;
					num = num + (s[j] - '0')*k;
					if(k < 0.01){
						flag = false;
						break;
					}
				}
			}
		}
		if(fuhao == false) num = -num;
		if(!(num>=-1000 && num<=1000) ){
			flag = false;
		}
		if(flag){
			count++;
			sum+=num;
		}else{
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
		}
	} 
	if(count == 0){
		cout<<"The average of "<<count<<" numbers is Undefined"<<endl;
	}else if(count == 1){
		cout<<"The average of "<<count<<" number is ";
		printf("%.2lf\n", sum / count);
	}else{
		cout<<"The average of "<<count<<" numbers is ";
		printf("%.2lf\n", sum / count);
	}
	return 0;
} 
