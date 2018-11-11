#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

bool visit[100005];
void dabiao(){
	memset(visit, true, sizeof(visit) );
	visit[1]=false;
	for(int i=2;i<100000;i++){
		if(visit[i]==true){
			for(int j=2;i*j<=100000;j++){
				visit[i*j]=false;
			}
		}	
	}
}

int main(){
	dabiao();
	/*
	for(int i=1;i<=100;i++){
		cout<<visit[i]<<" ";
	}*/
	int x,y;
	scanf("%d %d",&x,&y);
	int ans=0;
	for(int i=x;i<=y;i++){
		if(visit[i]==true){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
