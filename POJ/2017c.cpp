#include<iostream>
using namespace std;
int a[100][100],b[100][100];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int count =0;
			for(int p=-1;p<=1;p++){
				for(int q=-1;q<=1;q++){
					if(! (p==0 && q==0)){
						int x=i+p;
						int y=j+q;
						if( x<0 || x>=n || y<0 || y>=m){
							continue;
						}
						if(a[i][j]==1 && a[x][y]==1){
							count++;
						}else if(a[i][j]==0 && a[x][y]==1){
							count ++;
						}
					}
				}
			}
			if(a[i][j]==1){
				if(count <2 || count > 3){
					b[i][j]=0;
				}
			}else{
				if(count ==3){
					b[i][j]=1;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<b[i][j];
			if(j!=m-1){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
