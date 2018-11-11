#include<stdio.h>
int main(){
	int t;//<1000
	int count;
	int i;
	int j=0,o=0;
	unsigned int max=0;
	unsigned int a[3];
	scanf("%d",&t);
	while(t>0){
		t--;
		count=0;
		scanf("%u %u %u",&a[2],&a[1],&a[0]);
		
		if(a[0]==a[1] && a[1]==a[2]){
			printf("0\n");
			continue;
		}
		
		j=0,o=0;
		max=0;
		
		for(i=0;i<3;i++){
			if(a[i]%2==0){
				o++;
			}else{
				j++;
			}
			if(max<a[i]){
				max=a[i];
			}
		}
		
		count+=(max-a[0])/2;
		count+=(max-a[1])/2;
		count+=(max-a[2])/2;
		if((j==2&&max%2==1) || (j==1&&max%2==0)){ 
			count+=2;	
		}else if((j==2&&max%2==0) || (j==1&&max%2==1)){
			count+=1;
		}
		printf("%d\n",count);
	
	}
	return 0;
} 
