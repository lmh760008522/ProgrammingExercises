//描述
//输入三个字符（可以重复）后，按各字符的ASCII码从小到大的顺序输出这三个字符。
//输入
//第一行输入一个数N,表示有N组测试数据。后面的N行输入多组数据，每组输入数据都是占一行，有三个字符组成，之间无空格。
//输出
//对于每组输入数据，输出一行，字符中间用一个空格分开。
 
 //ok
 #include<iostream>
 using namespace std;

 int main(){
 	int n;
 	char que[3],t;
 	cin>>n;
 	while(n>0){
 		cin>>que[0]>>que[1]>>que[2];
 		if(que[0]>que[1]){
 				t=que[0];
			 	que[0]=que[1];
			 	que[1]=t;
		 }
		if(que[1]>que[2]){
 				t=que[1];
			 	que[1]=que[2];
			 	que[2]=t;
		 }
		 if(que[0]>que[1]){
 				t=que[0];
			 	que[0]=que[1];
			 	que[1]=t;
		 }
	n--;
	cout<<que[0]<<' '<<que[1]<<' '<<que[2]<<endl;
	} 
	return 0;
 }
