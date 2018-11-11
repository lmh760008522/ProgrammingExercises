#include<stdio.h>
#include<string.h>

struct link{
	char add[6];
	int data;
	char next[6];
};
int main(){
	int n,num;
	char addr[6];
	int i=0,j;
	struct link bin[10],right[10];//不能直接分配100000，太大会直接终止 
	scanf("%s%d %d",addr,&n,&num);
	while(i<n){
		scanf("%s %d %s",bin[i].add,bin[i].data,bin[i].next);
		i++;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(!strcmp(bin[j].add,addr)){
				right[i]=bin[j];
				strcpy(addr,bin[j].next);
				break;
			}
		}
	}
	for(i=1;i<=n/num;i++){
		for(j=i*num-1;j>(i-1)*num-1;j--){
			printf("%s %d %s\n",bin[j].add,bin[j].data,bin[j].next);
		}
	}
	for(j=(i-1)*num-1;j<n;j++){
		printf("%s %d %s\n",bin[j].add,bin[j].data,bin[j].next);
	}
	return 0;
}
 
