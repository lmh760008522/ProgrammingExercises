#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int main(){
	int t;
	scanf("%d\n",&t);
	set<char> jihe;
	char s[100];//���ֵ��Ŀû��������֪�������ٰ� 
	for(int i=0;i<t;i++){
		gets(s);
		
		int max=0;
		for(int j=0;j<strlen(s);j++){
			int ans=0;
			for(int k=j;k<strlen(s);k++){
				if( jihe.find(s[k]) == jihe.end()){
					jihe.insert(s[k]);
					ans++;
				}
			}
			if(max<ans){
				max=ans;
			}
			jihe.erase(s[j]);	
		}
		printf("%d\n",max);
	}
	return 0;
}
