//描述
//无穷数列1，1，2，3，5，8，13，21，34，55...称为Fibonacci数列，它可以递归地定义为
//F(n)=1 ...........(n=1或n=2)
//F(n)=F(n-1)+F(n-2).....(n>2)
//现要你来求第n个斐波纳奇数。（第1个、第二个都为1)
//输入
//第一行是一个整数m(m<5)表示共有m组测试数据
//每次测试数据只有一行，且只有一个整形数n(n<20)
//输出
//对每组输入n，输出第n个Fibonacci数

#include<iostream>

 using namespace std;
 
 int main(){
 	int n,num,i,a,b,ans;                      //占用多余空间！ 
 	cin>>n;
 	while(n>0){
 		cin>>num;
 		a=b=1;
 		if(num==1||num==2){
 			cout<<1<<endl;
		 }
		 else{
		 	for(i=1;i<=num-2;i++){            //循环里面改善 
		 		ans=b+a;
		 		a=b;
		 		b=ans;
		 		
			 }
			cout<<ans<<endl;
		 }
 		n--;
	 }
	 return 0;
 }
 
 
 
 /*
 int main(){
 	int m,n,i,s1,s2;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		for(i=3,s1=s2=1;i<=n;i++){
			s1=s1+s2;
			s2=s1-s2;
		}
		printf("%d\n",s1);
	}
}
 */
