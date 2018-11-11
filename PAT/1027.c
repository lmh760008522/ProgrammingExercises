#include<stdio.h>
int main(){
    char c;
    int num,count=2,k=1,i,j;
    scanf("%d %c",&num,&c);
    if(num>=1&&num<7){
        printf("%c\n%d",c,num-1);
        return 0;
    }
    do{
        k=k+2*(count*2-1);
        count++;
    }while(k<=num);
    //ÕâØíÐÐ×¢Òâ
    count--;
    k=k-2*(count*2-1);
    count--;
    //printf("%d\n",count);
    for(i=count;i>1;i--){
        for(j=count-i;j>0;j--){
            printf(" ");
        }
        for(j=(2*i-1);j>0;j--){
            printf("%c",c);
        }
        printf("\n");
    }
    for(j=count-i;j>0;j--){
        printf(" ");
    }
    printf("%c\n",c);
    for(i=2;i<=count;i++){
        for(j=count-i;j>0;j--){
            printf(" ");
        }
        for(j=(2*i-1);j>0;j--){
            printf("%c",c);
        }
        printf("\n");
    }
    printf("%d",num-k);
    return 0;
}
