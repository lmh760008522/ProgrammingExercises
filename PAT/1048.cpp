#include<stdio.h>
#include<string.h>
//������ȷ 
//�ܿӵ���Ŀ����������Ҫ�����B�ĳ���С��A������Bǰ������0���룬��Ŀ�в�û��˵��
int main(){
	char a[101]={0},b[101]={0};
	int i,j,count=1;
	scanf("%s %s",a,b);
	for(i=strlen(a)-1,j=strlen(b)-1;i>=0&&j>=0;i--,j--){
		if(count%2==0){//ż�� 
			b[j]=b[j]-a[i]+48;
			if(b[j]<'0'){
				b[j]+=10;
			}
		}else{
			b[j]=(b[j]-48+a[i]-48)%13;
			if(b[j]==10){
				b[j]='J';
			}else if(b[j]==11){
				b[j]='Q';
			}else if(b[j]==12){
				b[j]='K';
			}else{
				b[j]+=48;
			}
		}
		count++;
		
	}
	puts(b);
	return 0;
} 
