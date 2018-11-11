#include<cstdio>
 
int numday=0;
int dyear=0;
int num=0;

bool judge(int y){
	if( y%400 == 0 || (y%100!=0 && y%4==0)){
		return true;
	}
	return false;
}
int day(int m,int y){
	if( m == 1 || m == 3 || m == 5 || m == 7 || m == 8|| m == 10 || m==12){
		return 31;
	}else if(m==2){
		if(judge(y)){
			return 29;
		}else{
			return 28;
		}
	}else{
		return 30;
	}
}

int main(){
	int year,month;
	scanf("%d %d",&year,&month);
	bool falg = judge(year);//记录是否是闰年
	int numday = day(month,year);
	for(int i=1990;i<year;i++){
		if(judge(i)){
			num+=366;
		}else{
			num+=365;
		}
	}
	for(int i=1;i<month;i++){
		num+=day(i,year);
	}
	num=num+1;
	num%=7;
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	int count=0;
	for(int i=1;i<=num;i++){
		count++;
		printf("    ");
	}
	for(int i=1;i<10;i++){
		count++;
		if(count%7==0){
			printf("  %d\n",i);
		}else{
			printf("  %d ",i);
		}
	}
	for(int i=10;i<=numday;i++){
		count++;
		if(count%7==0){
			printf(" %d\n",i);
		}else{
			printf(" %d ",i);
		}
	}
	return 0;
}
