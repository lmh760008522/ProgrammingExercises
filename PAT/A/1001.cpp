#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

/*
类型名称        字节数    取值范围
signed char       1        -128～+127
short int         2        -32768～+32767                                
int               4        -2147483648～+2147483647                          
long int          4        -2147483648～+2141483647
long long long int  8      -9223372036854775808～+9223372036854775807
*/


/*
unsigned int  （unsigned long）
4字节8位可表达位数：2^32=42 9496 7296  
范围：0 ～ 42 9496 7295 (42*10^8)  

int  （long）
4字节8位可表达位数：2^32=42 9496 7296  
范围：-21 4748 3648 ～ 21 4748 3647 (21*10^8)

long long (__int64)
8字节8位可表达位数：2^64=1844 6744 0737 0960 0000  
范围：-922 3372 0368 5477 5808 ～ 922 3372 0368 5477 5807 (922*10^16)

unsigned long (unsigned __int64)
8字节8位可表达位数：2^64=1844 6744 0737 0960 0000  
范围：0 ～ 1844 6744 0737 0955 1615 (1844*10^16)
*/ 


void clc(char *a, char *b, int len){
	int c = 0;//进位
	for(int i = len; i > 0 ; i--){
		b[i] = b[i]-'0'+a[i]-'0'+ c + '0';
		c = b[i]-'0' >10 ? 1 : 0;
		b[i] = (b[i]-'0')%10 + '0';
	}
}

void sub(char *a, char *b, int len){//默认|b|>|a| 
	int c = 0;//借位
	for(int i = len; i > 0 ; i--){
		b[i]=b[i]-a[i]-c +'0';
		printf("%c", b[i]);
		c = b[i]-'0' <0 ? 1 : 0;
		b[i] = abs(b[i]-'0')+'0';
		printf("  修正：%c\n", b[i]);
	}
	printf("a:%s b:%s\n" ,a,b);
}

int change(char *a, char *b){
	int len_a = strlen(a);
	int len_b = strlen(b);
	if(len_a < len_b){//填充a 
		int i,j;
		for(i = len_b-1, j = len_a-1; i > 0 ; i--){
			if(j>0){
				a[i] = a[j];
				j--;
			}else{
				a[i]='0';
			}
		}
		printf("a:%s b:%s\n" ,a,b);
		return len_b;
	}else if(len_a > len_b){//填充b 
		int i,j;
		for(i = len_a-1 ,j = len_b-1; i > 0 ; i--){
			if(j>0){
				b[i] = b[j];
				j--;
			}else{
				b[i]='0';
			}
		}
	}
	printf("a:%s b:%s\n" ,a,b);
	return len_a;
}

int main(){
	int len_a, len_b;
	int len;
	char a[10], b[10];
	scanf("%s %s",a, b);
	if(a[0] == '-'){
		if(b[0] == '-'){//若 a b 都为- 
			len = change(a,b);
		    clc(a, b, len);
		}else{//a - b + ，比较绝对值 
			for(int i = strlen(b);i>0;i--){
				b[i] = b[i-1];
			}
			b[0]='0';

			if(strlen(a)>strlen(b)){//a-b
				len = change(a,b);
		        sub(b, a, len);
				b[0]='-';
			}else{//b-a
				len = change(a,b);
				sub(a, b, len);
			}
		}
	}else{
		for(int i = strlen(b);i>0;i--){
				b[i] = b[i-1];
		}
		b[0]='0';
		for(int i = strlen(a);i>0;i--){
			a[i] = a[i-1];
		}
		a[0]='0';
		len = change(a,b);
		clc(a, b, len);
	}
	
	if(b[0] == '-'){
		printf("-");
	}
	int i;
	for(i=1;i<len;i++){
		if(b[i]!='0'){
			break;
		}
	}
	if(i<len){
		for(;i<len;i++){
			printf("%c",b[i]);
			if((len - i )%3==1 && i!=(len-1)){
				printf(",");
			}
		}
	}else{//全为0的情况 
		printf("0"); 
	}
	return 0; 
} 
