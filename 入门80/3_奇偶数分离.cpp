//描述
//有一个整型偶数n(2<= n <=10000),你要做的是：先把1到n中的所有奇数从小到大输出，再把所有的偶数从小到大输出。
//输入
//第一行有一个整数i（2<=i<30)表示有 i 组测试数据；
//每组有一个整型偶数n。
//输出
//第一行输出所有的奇数
//第二行输出所有的偶数

 #include<iostream>
 using namespace std;
 int main(){
 	int n,num,i;
 	cin>>n;
 	while(n>0){
 		cin>>num;
 		for(i=1;i<num;i=i+2){
 			cout<<i<<' ';
		 }
		 cout<<'\n';
		for(i=2;i<=num;i=i+2){
 			cout<<i<<' ';
		 }
 		n--;
	 }
 	return 0;
 }
