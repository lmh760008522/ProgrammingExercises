#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		int m[100];
		int p[100];
		int maxp=0;
		for(int j=0;j<n;j++){
			cin>>m[j];
		}
		for(int j=0;j<n;j++){
			cin>>p[j];
			if(p[j]>maxp){
				maxp=p[j];
			}
		}
		if(k>=m[n-1]){
			cout<<maxp<<endl;
			continue; 
		}
		int tempp, tempm;
		maxp=0;
		for(int j=0;j<n;j++){
			tempp=p[j];
			tempm=m[j];
			for(int q=j+1;q<n;q++){
				if(tempm+k<=m[q]){
					tempm=m[q];
					tempp+=p[q];
					if(tempp>maxp){
						maxp=tempp;
					}
				}else if( tempm+k>m[n-1] ){
					break;
				}
			}
		}
		cout<<maxp<<endl;
	}
	return 0;
}
