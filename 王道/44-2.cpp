#include<cstdio>
#include<string.h>
#include<stack>
using namespace std;
int main(){
	char a[205];
	stack<char> s;
	stack<double> ans;
	gets(a);
	s.push(',');
	while(a!="0"){
		for(int i=0;i<strlen(a);i++){
			if(a[i] == '+' || a[i] == '-'){
				s.push( a[i] );
			}else if( a[i] == '*' || a[i] == '/'){
				int x=ans.top();
				ans.pop();
				int y=0;
				int k;
				for(k=i+1; !(a[k]=='+' || a[k]=='-' || a[k]=='*' || a[k]=='/' ) && k<strlen(a) ;k++){
					y=y*10;
					y+=a[k]-'0';
				}
				//printf("x:%d y:%d x/y=%lf\n",x,y,double(x)/y);
				//printf("%c ",a[i]);
				if( a[i] == '*' ){
					//printf("x:%d y:%d x*y=%d\n",x,y,x*y);
					ans.push(x*y);
				}else{
					ans.push(double(x)/y);
				}
				i=k-1;
			}else{
				//printf("a[i]-'0':%d\n",a[i]-'0');
				int num=0;
				for(int k=i; !(a[k]=='+' || a[k]=='-' || a[k]=='*' || a[k]=='/' ) && k<strlen(a);k++){
					num=num*10;
					num+=a[k]-'0';
					i=k;
				}
				ans.push(num);
			}
		}
		while(s.top()!=','){
			//printf("%lf\n",ans.top());
			double x=ans.top();
			ans.pop();
			//printf("%lf\n",ans.top());
			double y=ans.top();
			ans.pop();
			if(s.top()=='+'){
				ans.push(x+y);
			}else{
				ans.push(y-x);
			}
			s.pop();
		}
		
		printf("%.2lf\n",ans.top());
		ans.pop();
		
		gets(a);
	}
	return 0;
} 
