//����
//���������ַ��������ظ����󣬰����ַ���ASCII���С�����˳������������ַ���
//����
//��һ������һ����N,��ʾ��N��������ݡ������N������������ݣ�ÿ���������ݶ���ռһ�У��������ַ���ɣ�֮���޿ո�
//���
//����ÿ���������ݣ����һ�У��ַ��м���һ���ո�ֿ���
 
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
