//��ջ��ջʹ�� 

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

/*����һ 
ע�⣺�ںڿ����ֶ�����ʱ��ϵͳ����֪��ʲôʱ�򵽴�����ν�ġ��ļ�ĩβ���������Ҫ��< Ctrl + Z >��ϼ���Ȼ��< Enter >���ķ�ʽ������ϵͳ�Ѿ����� EOF������ϵͳ�Ż���� while
#include<cstdio>
int main(){
    int num = 0;    //���ʵĸ���
    char ans[80][80];
    while(scanf("%s", ans[num]) != EOF){    //һֱ����ֱ���ļ�ĩβ
        num++;      //���ʵĸ����� 1 
    }
    for(int i = num - 1; i >= 0; i--){      //�����������
        printf("%s", ans[i]);
        if(i > 0) printf(" "); 
    }
    return 0;
} 
*/ 

/*������ 
#include<cstdio>
#include<cstring>

int main(){
    char str[90];
    gets(str);
    int len = strlen(str), r = 0, h = 0;    // r Ϊ�У�h Ϊ��
    char ans[90][90];           // ans[0] ~ ans[r] ��ŵ���
    for(int i = 0; i < len; i++){
        if(str[i] != ' '){      //�����ǿո������� ans[r][h]������ h++
            ans[r][h++] = str[i]; 
        }else{                  //���ǿո�˵��һ�����ʽ������� r ���� 1���� h �ָ��� 0 
            ans[r][h] = '\0';   //ĩβ�ǽ����� \0 
            r++;
            h = 0; 
        }
    }
    for(int i = r; i >= 0; i--){//����������ʼ���
        printf("%s", ans[i]);
        if(i > 0) printf(" "); 
    }
    return 0;
} 
*/ 
