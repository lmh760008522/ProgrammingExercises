//����
//��������һ����λ���ֻ�����ͬ����λ���������е����ִӴ�С�����õ�a,��С�����õ�b,Ȼ����a-b�滻ԭ������������Ҽ������������磬��1234���������ο��Եõ�4321-1234=3087��8730-378=8352��8532-2358=6174���ֻص������Լ�������Ҫ��дһ���������ж�һ����λ���������ٴ������Ĳ����ܳ���ѭ����������������Ĵ���
//
//��������1234ִ��˳����1234->3087->8352->6174->6174,�����4
//
//����
//��һ������n,������n��������ݡ�
//������n��ÿ�ж�дһ����λ���ֻ�����ͬ����λ��
//���
//�������ٴ����������Ĳ������ܳ���ѭ��


//timelimited
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,count=1,que[4],t,max,min,a,b,i,j;
	cin>>n;
	while(n>0){
		cin>>b;
		while(true){
			for(i=0;i<4;i++){
				que[i]=(b%int((pow(10,4-i))))/(pow(10,3-i));
			}
			//�Ӵ�С���� ///#include<algorithm> sort(a,a+4) 
	 		for(i=0;i<3;i++){
	 			for(j=0;j<4-i;j++){
	 				if(que[j]<que[j+1]){
	 					t=que[j];
				 		que[j]=que[j+1];
				 		que[j+1]=t;
					 }
				 }
			 } 
			 max=1000*que[0]+100*que[1]+10*que[2]+que[3];
			 min=1000*que[3]+100*que[2]+10*que[1]+que[0];
			 a=max-min;
			 if(a==b){
			 	cout<<(count-1)<<endl;
				break;
			 }else{
			 	b=a;
				count++;
			}
			//	cout<<max<<' '<<min<<' '<<a<<' '<<(count-1)<<endl; 
		}
		n--;
	} 
	return 0;
} 

 
//#include<iostream>
//#include<algorithm>
//#include<stdio.h>
//using namespace std;
//int main()
//{
//	//freopen("1.txt","r",stdin);
//	int k;
//	cin>>k;
//	while(k--)
//	{
//		int n,a[4],n1,n2;
//		scanf("%d",&n);
//		int s=1;
//		while(n!=6174)										///ע���ҹ��� 
//		{
//			a[0]=n%10;
//			a[3]=n/1000;
//			a[1]=n/10%10;
//			a[2]=n/100%10;
//			sort(a,a+4);
//			n1=1000*a[3]+100*a[2]+10*a[1]+a[0];
//			n2=1000*a[0]+100*a[1]+10*a[2]+a[3];
//			n=n1-n2;										///ע������滻 
//			s++;
//		}
//		printf("%d\n",s);
//	}
//}        
