#include<stdio.h>
#include<string.h>
//部分正确 
//很坑的题目，测试例子要求如果B的长度小于A，则在B前边填上0补齐，题目中并没有说。
int main(){
	char a[101]={0},b[101]={0};
	int i,j,count=1;
	scanf("%s %s",a,b);
	for(i=strlen(a)-1,j=strlen(b)-1;i>=0&&j>=0;i--,j--){
		if(count%2==0){//偶数 
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
