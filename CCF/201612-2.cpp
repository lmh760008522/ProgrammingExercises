///错误，列表达式 

#include<stdio.h>
int main(){
	int t;
	scanf("%d" ,&t); 
	if( t == 0){
		printf("<3500");
	}else if(t > 0 && t<=45){
		t = t/0.03;
		printf("%d", 3500+t);
	}else if( t>45 && t<=345){
		t = t-45;
		t = t/0.1;
		printf("%d", 3500+1500+t);
	}else if( t>345 && t<=1245){
		t = t-345;
		t = t/0.2;
		printf("%d", 3500+4500+t);
	}else if( t>1245 && t<=7745){
		t = t-1245;
		t = t/0.25;
		printf("%d", 3500+9000+t+);
	}else if( t>7745 && t<=13745){
		t = t-7745;
		t = t/0.3;
		printf("%d", 3500+35000+t);
	}else if( t>13745 && t<=22495){
		t = t-13745;
		t = t/0.35;
		printf("%d", 3500+13745+t);
	}else{
		t = t-22495;
		t = t/0.45;
		printf("%d", 3500+80000+t);
	}
	return 0;
}
