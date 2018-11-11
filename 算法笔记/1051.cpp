#include<cstdio>
#include<stack>
using namespace std;

int main(){
	int m,n,k;
	scanf("%d %d %d\n",&m,&n,&k);
	char s[100];
	stack<int> ss;
	for(int i=0;i<k;i++){
		gets(s);
		ss.push(0);
		int num=1;
		int len=0;
		for(int j=0;j<n;j++){
			while( (s[j]-'0') != ss.top() && len<=m){
				ss.push(num);
				len++;
				num++;
				printf("%d %d ? ",s[j]-'0',ss.top());
			}
			if(num>n+1){
				printf("1NO\n");
				break;
			}
			if(len>m){
				printf("2NO\n");
				break;
			}
			if((s[j]-'0')==ss.top()){
				ss.pop();
				len--;
				continue;
			}
		}
		if(ss.top()==0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
} 
