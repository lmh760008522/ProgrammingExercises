#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std; 
int main(){
    int x,z,i=0;//xΪϵ����zΪָ��
    int xs[2001],zs[2001];//ϵ����ָ�� 
    
    do{
    	cin>>xs[i]>>zs[i];
    	i++;
	}while(getchar()==' ');
	
    for(i=0;xs[i]!='\0';i++){
        xs[i]=xs[i]*zs[i];
        if(zs[i]!=0){
        	zs[i]--;
		}
        
       // printf("%d %d ",xs[i],zs[i]);
    }
    
    for(i=0;xs[i+1]!='\0';i++){
        //if(zs[i]!=-1){
        	printf("%d %d ",xs[i],zs[i]);
	//	}
    }
    //if(zs[i]!=-1){
        printf("%d %d",xs[i],zs[i]);
	//}
    return 0;
}
