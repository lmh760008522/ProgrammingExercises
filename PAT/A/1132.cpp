#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
	int n;
	for(int i=0;i<n;i++){
		string z;
		cin>>z;
		int a = stoi(z.substr(0, z.length()/2));
        int b = stoi(z.substr(z.length()/2));
        int c = stoi(z);
        if(a==0 ||b==0){//注意切割后为0的情况 
        	printf("No\n"); 
        	continue;
		}
        if(z % (a*b) ==0){
        	printf("Yes\n");
		}else{
			printf("No\n"); 
		}
	}
	return 0;
} 
