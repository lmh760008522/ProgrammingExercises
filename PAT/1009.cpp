//进栈出栈使用 

#include<string.h>
#include<stack>
#include<iostream>
using namespace std;
int main(){
	int i,count=0;
	char s[80];
	char c;
	stack<char> sta;
	gets(s);
	for(i=strlen(s)-1;i>=0;i--){
		if(s[i]!=' '){
			sta.push(s[i]);
			count++;
		}else{
			while(count>0){
				c=sta.top();
				sta.pop();
				cout<<c;
				count--;
			}
			cout<<' ';
			count=0;
		}
	}
	while(count>0){
		c=sta.top();
		sta.pop();
		cout<<c;
		count--;
	}
	return 0;
} 

/*方法一 
注意：在黑框中手动输入时，系统并不知道什么时候到达了所谓的“文件末尾“，因此需要用< Ctrl + Z >组合键，然后按< Enter >键的方式来告诉系统已经到了 EOF，这样系统才会结束 while
#include<cstdio>
int main(){
    int num = 0;    //单词的个数
    char ans[80][80];
    while(scanf("%s", ans[num]) != EOF){    //一直输入直到文件末尾
        num++;      //单词的个数加 1 
    }
    for(int i = num - 1; i >= 0; i--){      //倒着输出单词
        printf("%s", ans[i]);
        if(i > 0) printf(" "); 
    }
    return 0;
} 
*/ 

/*方法二 
#include<cstdio>
#include<cstring>

int main(){
    char str[90];
    gets(str);
    int len = strlen(str), r = 0, h = 0;    // r 为行，h 为列
    char ans[90][90];           // ans[0] ~ ans[r] 存放单词
    for(int i = 0; i < len; i++){
        if(str[i] != ' '){      //若不是空格，则存放至 ans[r][h]，并令 h++
            ans[r][h++] = str[i]; 
        }else{                  //若是空格，说明一个单词结束，行 r 增加 1，列 h 恢复至 0 
            ans[r][h] = '\0';   //末尾是结束符 \0 
            r++;
            h = 0; 
        }
    }
    for(int i = r; i >= 0; i--){//倒着输出单词即可
        printf("%s", ans[i]);
        if(i > 0) printf(" "); 
    }
    return 0;
} 
*/ 
