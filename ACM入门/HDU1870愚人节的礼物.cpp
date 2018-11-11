#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;

int main(){
	char s[1005];
	while(scanf("%s", s) ){
		if(s == "\n"){
			break;
		}
		int sum = 0;
		stack<char> st;
		for(int i=0; i<strlen(s); i++){
			if(s[i] == '('){
				st.push('(');
			}else if(s[i] == ')'){
				st.pop();
			}else{
				while(!st.empty()){
					st.pop();
					sum++;
				}
				break;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
} 

/*
优化：实际上并不需要一个堆栈，只要按照堆栈的处理过程进行即可。
 
#include <iostream>
 
using namespace std;
 
int main()
{
    string s;
    int level, i;
 
    while(getline(cin, s)) {
        level = 0;
        i = 0;
        while(s[i]) {
            if(s[i] == 'B')
                break;
            else if(s[i] == '(')
                level++;
            else if(s[i] == ')')
                level--;
 
            i++;
        }
 
        cout << level << endl;
    }
 
    return 0;
}

*/
