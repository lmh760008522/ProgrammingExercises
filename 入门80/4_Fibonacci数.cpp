//����
//��������1��1��2��3��5��8��13��21��34��55...��ΪFibonacci���У������Եݹ�ض���Ϊ
//F(n)=1 ...........(n=1��n=2)
//F(n)=F(n-1)+F(n-2).....(n>2)
//��Ҫ�������n��쳲�������������1�����ڶ�����Ϊ1)
//����
//��һ����һ������m(m<5)��ʾ����m���������
//ÿ�β�������ֻ��һ�У���ֻ��һ��������n(n<20)
//���
//��ÿ������n�������n��Fibonacci��

#include<iostream>

 using namespace std;
 
 int main(){
 	int n,num,i,a,b,ans;                      //ռ�ö���ռ䣡 
 	cin>>n;
 	while(n>0){
 		cin>>num;
 		a=b=1;
 		if(num==1||num==2){
 			cout<<1<<endl;
		 }
		 else{
		 	for(i=1;i<=num-2;i++){            //ѭ��������� 
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
