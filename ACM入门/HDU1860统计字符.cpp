#include<stdio.h>
#include<map>
#include<string.h>
using namespace std;

int main(){
	char s1[6], s2[105];
	scanf("%s\n%s\n", s1, s2);
	while( s1 != "#"){
		map<char,int> m;
		for(int i=0; i<strlen(s2); i++){
			m[ s2[i]]++;
		}
		for(int i=0; i<strlen(s1); i++){
			printf("%c %d\n",s1[0], m[ s1[i]]);
		} 
		scanf("%s\n%s\n", s1, s2);
	}
	return 0;
} 

/*
注意答案的输出 
 
#include <iostream>
#include <string>
 
using namespace std;
 
const string END = "#";
 
int main()
{
    string character, s;
    int count;
 
    while(getline(cin, character)) {
        if(character == END)
            break;
 
        getline(cin, s);
 
        for(int i=0; i<(int)character.size(); i++) {
            count = 0;
            for(int j=0; j<(int)s.size(); j++)
                if(s[j] == character[i])
                    count++;
            cout << character[i] << " " << count << endl;
        }
    }
    return 0;
}

*/
