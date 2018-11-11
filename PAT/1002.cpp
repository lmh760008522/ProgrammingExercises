#include<iostream>
using namespace std;
#include<stdio.h>
#include<cmath> 

//一个测试用例无法通过，不知道为啥，逻辑没有问题 
void out(int i){
	switch(i){
		case 1: printf("yi");break;
		case 2: printf("er");break;
		case 3: printf("san");break;
		case 4: printf("si");break;
		case 5: printf("wu");break;
		case 6: printf("liu");break;
		case 7: printf("qi");break;
		case 8: printf("ba");break;
		case 9: printf("jiu");break;
		case 0: printf("ling");break;
	}
}
int main(){
	char c[101];                                //！！10的100次方是101位数！！ 
	int i,sum=0;
	gets(c);
	for(i=0;c[i]!='\0';i++){
		sum+=c[i]-48;                         //！注意字符和数字的转换 
	}
	i=100;
	if(sum==0){                                   //特殊值 
		out(0);
	}else{
		while(sum!=0){
		if(sum/i!=0){
			out(sum/i);
			if(i!=1){
				cout<<" ";
			}
		}
		sum=sum-(sum/i)*i;
		i=i/10;
	}
	}

	return 0;
}


/*
#include<iostream>
using namespace std;


void int_pinyin(int a){
	switch(a){
		case 0:cout<<"ling";break;
		case 1:cout<<"yi";break;
		case 2:cout<<"er";break;
		case 3:cout<<"san";break;
		case 4:cout<<"si";break;
		case 5:cout<<"wu";break;
		case 6:cout<<"liu";break;
		case 7:cout<<"qi";break;
		case 8:cout<<"ba";break;
		case 9:cout<<"jiu";break;	
	}
}


int main(){
	char a[101];
	cin>>a;
	int sum=0,i=0;
	while(a[i]!='\0'){
		sum+=a[i]-'0';
		++i;
	}
	//cout<<sum<<"\n";
	
	int b[11],j=0;
	if(sum==0){
		int_pinyin(0);
		return 0;
	}
	
	while(sum!=0){
		b[j]=sum%10;
		//cout<<b[j]<<" ";
		sum=sum/10;
		++j;
	}
	
	for(int i=j-1;i>0;--i){
		int_pinyin(b[i]);
		cout<<" ";
	}
	int_pinyin(b[0]);
	return 0;
}
*/ 
