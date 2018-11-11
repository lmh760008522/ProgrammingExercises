#include<stdio.h>
#include<string.h>

long long int change(char c){
	if(c>='0'||c<='9'){
		return c-'0';
	}else{
		return c-'a'+10;
	}
}

long long int turnto10(char *n,long long radix){
	int i;
	long long int ans=0;
	for(i=0;i<strlen(n);i++){
		ans=ans*radix+change(n[i]);                  //!画重点，不要用pow 
	}
	return ans;
}

 

int main(){
	char n1[15],n2[15];
	long long tag,radix;//我也不知道为啥是long long 
	long long radix1,radix2;
	long long int i,j;
	scanf("%s %s %lld %lld", n1, n2 ,&tag, &radix1);
	if(tag==2){
		char temp[15];
		strcpy(temp , n1);
		strcpy(n1 , n2);
		strcpy(n2 ,temp);
	}
	
	//long long maxr,minr;
	
	long long int ans1;
    //先把第一个数转化成十进制
	ans1=turnto10(n1,radix1);
	
	long long int maxnum=0;
	for(i=0;i<strlen(n2);i++){//找最大的数字作为进制最小值 
		if(maxnum<change(n2[i])){
			maxnum=change(n2[i]);
		}
	}
	
	/* 
	long long int ans2;
	for(i=maxnum+1; ; i++){
		ans2=turnto10(n2,i);
		if(ans2>=ans1){//要找到最大值然后二分法找，最大应为第一个数 
			break;
		}
	}
	*/
	
	long long int ans2;
	long long int max,min;
	max=ans1;
	min = maxnum+1;
	while(min <= max){
		i=(min+max)/2;
		ans2=turnto10(n2,i);
		if(ans1 < ans2) {
			max = i-1;
		}else if(ans1 > ans2){
			min = i+1;
		}else{//找到了 
			printf("%lld", i);
			return 0;
		}
	}
	printf("Impossible");
	return 0;
} 
