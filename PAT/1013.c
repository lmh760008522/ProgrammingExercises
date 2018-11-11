#include<stdio.h>
#include<math.h>

int judge(int i){
    int t;
    for(t=2;t<=sqrt(i);t++){
            if(i%t==0){
                return 0;
            }
        }
        return 1;
}

int main(){
    int prime[10000];
    int i,j;
    int m,n,count=0;
    prime[0]=2;
    prime[1]=3;
    for(i=4,j=2;j<10000;i++){
        if(judge(i)==1){
            prime[j]=i;
            j++;
        }
    }
    scanf("%d %d",&m,&n);
    for(i=m-1;i<n-1;i++){
        printf("%d",prime[i]);
        count++;
        if(count%10==0){
            printf("\n");
        }else{
            printf(" ");
        }
    }
    printf("%d",prime[i]);
    return 0;
}
