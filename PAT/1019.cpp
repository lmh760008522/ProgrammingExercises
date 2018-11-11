#include<stdio.h>
#include<stdlib.h> 
//答案错误，没有对的。。。 
int main(){
	char a[4],c;
	int i,j,max=0,min=0,cha,count;
	scanf("%s",a);
	
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]){
		printf("%c%c%c%c - %c%c%c%c = 0000\n",a[0],a[0],a[0],a[0],a[0],a[0],a[0],a[0],a[0]);
		return 0;
	}
	
	while(1){
		
	for(i=0;i<3;i++){//排序 
		for(j=0;j<4-i;j++){
			if(a[j]<a[j+1]){
				c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
	}
	
	for(i=0;i<4;i++){
		printf("%c",a[i]);
	}
	printf(" - ");
	for(i=3;i>=0;i--){
		printf("%c",a[i]);
	}
	printf(" = ");
	
	count=1000;
	max=0;
	for(i=0;i<4;i++){
		max+=count*(a[i]-48);
		count=count/10;
	}
	
	count=1000;
	min=0;
	for(i=3;i>=0;i--){
		min+=count*(a[i]-48);
		count=count/10;
	}


	cha=max-min;
	
	if(cha==6174){
		break;
	}
	for(i=3;i>=0;i--){
		a[i]=cha%10+48;
		cha=cha/10;
	}
	for(i=0;i<4;i++){
		printf("%c",a[i]);
	}
	printf("\n");
	//system("pause");
}
	for(i=3;i>=0;i--){
		a[i]=cha%10;
		//cha=cha/10;
	}
	printf("6174\n");
	
	return 0;
} 

/*
#include <stdio.h>  
#include <algorithm>  
using namespace std;  
int inc, de;  
void gao(int x){  
    int a[4];  
    a[0] = x / 1000;  
    a[1] = x / 100 % 10;  
    a[2] = x / 10 % 10;  
    a[3] = x % 10;  
    sort(a, a + 4);  
    inc = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];  
    de = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];  
}  
  
int main(){  
    int n, s;  
    scanf("%d", &n);  
    if ((n / 1000 == n / 100 % 10) && (n / 1000 == n / 10 % 10) && (n / 1000 == n % 10)){  
        printf("%04d - %04d = 0000\n", n, n);  
        return 0;  
    }  
    do{  
        gao(n);  
        s = de - inc;  
        printf("%04d - %04d = %04d\n", de, inc, s);  
        n = s;  
    } while (s != 6174);  
    return 0;  
}  
*/
