#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream> 
using namespace std;
//40min,一开始想用数据类型表示，结果发现结果无法控制位数，因此用数组 
//一个正确，一个段错误，剩下错误 
int main(){
	char fuhao1,fuhao2,jieguo[250];
	char c[1000];
	int i,j,count=0;
	double jishu=0;
	int zhishu=0;
	scanf("%c%s",&fuhao1,c);
	for(i=1;i<strlen(c);i++){
		if(c[i]=='E'){
			j=i;
			fuhao2=c[i+1];
		}
	}
	for(i=strlen(c)-1;i>=j+2;i--){
		zhishu+=(c[i]-48)*pow(10,count);// ----->>>>after = (s[i] - '0') + 10 * after; 
		count++;
	}
	//printf("%lf %d\n",jishu,zhishu);
	strncpy(jieguo,c,j);
	if(zhishu==0){
		puts(jieguo);
		return 0;
	}
	if(fuhao1=='-'){
		printf("%c",fuhao1);
	}
	if(fuhao2=='-'){
		printf("0.");
		zhishu-=1;
		while(zhishu>0){
			printf("0");
			zhishu--;
		}
		printf("%c",jieguo[0]);
		for(i=2;i<strlen(jieguo);i++){
			printf("%c",jieguo[i]);
		}
	}else{
		for(i=2;i<strlen(jieguo);i++){
			if(zhishu>0){
				printf("%c",jieguo[i]);
				zhishu--;
			}else if(zhishu==0){
				printf(".");
				break;
			}
		}
		if(i!=strlen(jieguo)){
			for(;i<strlen(jieguo);i++){
				printf("%c",c[i]);
			}
		}else{
			while(zhishu>0){
				printf("0");
				zhishu--;
			}
		}
	}
	return 0;
}  
