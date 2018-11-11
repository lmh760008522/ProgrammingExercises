#include<stdio.h>
#include<string.h>
char a[4][50];
int num[3];
void zhuanhuan(int i, int x){
	int j = 0;
	while(x != 0){
		a[i][j++] = x%10 + '0';
		x = x/10;
	}
	a[i][j] = '\n';
}
void plus(int long_x, int short_x){//short_x的长度 <= long_x的长度 
	int c = 0;//进位 
	int i;
	for(i = 0; a[short_x][i] != '\n'; i++){
		a[long_x][i] = a[long_x][i] + a[short_x][i] + c - '0';
		if(a[long_x][i] >'9'){
			c = 1;
			a[long_x][i] -= 10;
		}else{
			c = 0;
		}
	}
	if(c != 0){
		for( ;a[long_x][i] != '\n' && c!=0 ; i++){
			a[long_x][i] += c;
			if(a[long_x][i] >'9'){
				c = 1;
				a[long_x][i] -=10;
			}else{
				c = 0;
			}
		}
	}
	if(c != 0){
		a[long_x][i] = '1';
		a[long_x][i+1] = '\n';
	}
}
int main(){
	while( scanf("%d %d %d", &num[0], &num[1], &num[2]) != EOF){
		for(int i=0;i<3;i++){
			zhuanhuan(i,num[i]);
		}
		int count;
		for(count = 3; count<=99; count++){
			int j;
			for(j=0; a[(count-1)%4][j]!='\n'; j++){
				a[count%4][j] = a[(count-1)%4][j];
			}
			a[count%4][j] = '\n';
			plus(count%4,(count-2)%4);
			plus(count%4,(count-3)%4);
		}
		for(int i = strlen(a[99%4])-2; i>=0; i--){//倒叙输出 
			printf("%c", a[99%4][i]);
		}
		printf("\n");
	}
	return 0;
}
