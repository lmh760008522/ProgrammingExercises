/*
�ַ��� 
������˾���1Сʱ�� 
real numbers��ʵ�� 
accurate up to����ȷ�� 
2 decimal places����λС�� 
��N��ʵ�� �������������������ƽ��ֵ��
�������������Ƿ�Χ��[-1000,1000]�����֣����Ҿ�ȷ����λС�� �� 
*/
//���������� :���ⲻ�壬��Ŀ��˵1����number����numbers 
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
			}else if(s[j] == '.' && exist == false && j == 0){// .2�ǲ���ȷ�� 
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
