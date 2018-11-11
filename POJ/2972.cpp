#include<iostream>
using namespace std;
//没有判断进制的最低下线 
int main(){
	int n;
	for(int i=0;i<n;i++){
		int q,p,r;
		cin>>q>>p>>r;
		int m;
		for(m; m<=16 ; m++){
			int a=q,b=p,c=r;
			int aa=0,bb=0,cc=0;
			int count=1;
			while(a>0){
				aa+=(a%10)*count;
				count*=m;
				a=a/10;
			}
			count =1;
			while(b>0){
				bb+=(b%10)*count;
				count*=m;
				b=b/10;
			}
			count =1;
			while(c>0){
				cc+=(c%10)*count;
				count*=m;
				c=c/10;
			}
			cout<<aa<<" "<<bb<<" "<<cc<<endl;
			if(aa*bb==cc){
				cout<<m<<endl;
				break;
			} 
		}
		if(m==17){
			cout<<0<<endl;
		}
		
	}
	
	return 0;
} 
