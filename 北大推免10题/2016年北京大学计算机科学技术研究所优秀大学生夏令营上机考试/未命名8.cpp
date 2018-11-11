#include<cstdio>
#include<cmath>

long long jiecheng(int n){
	if(n==1){
		return 1;
	}
	return n*jiecheng(n-1);
}

int main(){
	int n,m,k;
	while( scanf("%d %d %d",&n,&m,&k)!=EOF){
		if(n==0 && m==0 && k==0){
			break;
		}
		
		long long pbox=jiecheng(m);//���ӵ����� 
		int tempn=n-m*k;
		if(tempn<0){
			printf("0\n");
			continue;
		}
		int psheng=pow(m,tempn);//�޳������ʣ�µİڷŷ�������ʱΪ���� 
		//int psheng=pow(2,m+1)-1-(m+1);// �޳������ʣ�µİڷŷ�������ʱΪ����
		int pdui = 1;
		if(k!=0){
			pdui = jiecheng(m*k)/jiecheng(k);//�ֳ�m�ѣ�ÿ��k���ķ���������  A(n,n)/A(k,k)	
		}
		//printf("%d %d %d %lld\n",pdui,psheng,pbox,pdui*psheng);
		printf("%lld\n",pdui*psheng);
		//printf("%d\n",jiecheng(n));
	}
	return 0;
}
