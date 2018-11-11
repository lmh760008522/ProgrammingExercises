#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 89080 // 1000001��Χ������prime���������ޣ������ȳ������
#define Maxx 1000010 // 4n+1�����Ϊ1000001
int Sum[Maxx]; // �������
int prime[Max]; // ����prime��
bool flag[Maxx]; // �ж��Ƿ�Ϊprime��
int num,h; // numΪprime������
void prime_table(int n){// ɸ����prime�������뼸����ɸ��������һ������Ϊ˼��һ��
	int i,j,pivot=0;
	memset(flag,0,sizeof(flag)); // ȫ����ʼ��Ϊ����prime��
	prime[pivot++]=5;
	flag[5]=true; //ɸ�����Ĵ���
	for(i=9;i<=n;i+=4){
		bool trag=true;
		for(j=0;prime[j]*prime[j]<=i;j++)
			if(i%prime[j]==0)
				trag=false;
		if(trag){ //��Ϊprime������flag����Ϊtrue
			prime[pivot++]=i;
			flag[i]=true;
		}
	}
	num=pivot; // prime������
}
void Get_num(int h){ // �ж��Ƿ�Ϊsemi-prime�����ٴι����д�ڶ��ű�
	int i,j;
	Sum[1]=0;//1����1��Χ��semi-prime����Ϊ0
	for(i=5;i<=h;i+=4){ // �ڶ���4n+1��Ϊ5��������Ϊ9��  13 ������
		if(flag[i]){ // ��֦����Ϊprime������ض�����semi-prime����Sum[i]=Sum[i]=Sum[i-4];
			Sum[i]=Sum[i-4];
			continue;
		}
		j=0;
		bool trag=false; // ���ñ�� ��ע��j<num��������û�и��������������Ϊj>=num����������Ԥ֪�Ľ������ѭ����
		while(j<num && prime[j]*prime[j]<=i){ // ��֦�ؼ������������н�С��ƽ��ҪС�ڵ��ڳ˻�����
			if(i%prime[j]==0 && flag[i/prime[j]]){
				trag=true;
				break;
			}
			j++;
		}
		if(trag) // ��Ϊsemi-prime������Sum[i]=Sum[i-4]+1;
			Sum[i]=Sum[i-4]+1;
	    else
			Sum[i]=Sum[i-4];
	}
}
int main(){
	prime_table(1000001); // ���һ�ű�
	Get_num(1000001); // ��ڶ��ű�
	while(scanf("%d",&h),h) 
		printf("%d %d\n",h,Sum[h]); // ֱ�����
	return 0;
}
