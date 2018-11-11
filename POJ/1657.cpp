#include<iostream>
using namespace std;
int pan[8][8];
//Ë¼Â·¸´ÔÓÁË 
int w(int x1,int y1,int x2,int y2,int count){
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(x1+i>=0 && y1+j >=0 && x2+i<=7 && y2+j<=7){
				x1+=i;
				y1+=i;
				count++;
				if( x1 == x2 && y1 == y2){
					return count;
				}else{
					w(x1,y1,x2,y2,count);
				}
			}else{
				continue;
			}
		}
	} 
	return -1;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		char a[2],b[2];
		cin>>a>>b;
		int x1,y1,x2,y2;
		x1 = a[1]-'0'-1;
		y1 = 7-(a[0]-'a');
		x2 = b[1]-'0'-1;
		y2 = 7-(b[0]-'a');
		cout<<"("<<x1<<","<<y1<<")"<<"("<<x2<<","<<y2<<")"<<endl;
		cout<< w(x1,y1,x2,y2,0);
	}
	
	return 0;
} 
