#include<iostream>
#include<stack>
#include<string>
using namespace std;

void pprint(int x){
	switch(x){
		case 1:printf("one");break;
		case 2:printf("two");break;
		case 3:printf("three");break;
		case 4:printf("four");break;
		case 5:printf("five");break;
		case 6:printf("six");break;
		case 7:printf("seven");break;
		case 8:printf("eight");break;
		case 9:printf("nine");break;
		case 0:printf("zero");break;
	}
}

int main(){
	char s[1005];
	gets(s);
	int sum=0;
	for(int i=0;s[i]!='\0';i++){
		sum+=s[i]-'0';
	}
	stack<int> st;
	int num=0;
	while(sum!=0){
		st.push(sum%10);
		sum=sum/10;
		num++;
	}
	while(st.empty()==false){
		int a = st.top();
		st.pop();
		pprint(a);
		if(num!=1){
			printf(" ");
		}
		num--;
	}
	return 0;
} 
