#include<stdio.h>
#include<string.h>

//不会做，耗时：1h，想复杂了？？
int main(){
    char a[1001];
    int q[1001]={0};//倒序存储
    int b,r,len1,t,j=0,i=0;
    scanf("%s %d\n",a,&b);
    len1=strlen(a);
    while(i!=-1){
        if(a[len1]-48-b<0){
            for(i=len1-2;a[i]==0&&i>=j;i--){
                a[i]=a[i]+9;
            }
            a[i]-=1;
            a[len1]=a[len1]+10-b;
        }else{
            a[len1]-=b;
        }
        if(a[j]=='0'){
            j++;
        }

        q[0]++;
        for(i=0;q[i]+1==10;i++){
            q[i]=0;
        }
        q[i]++;

        for(i=0;i<len1-1;i++){
            if(a[i]=='0'){
                break;
            }
        }
        if(a[i]<b){
            r=a[i]-48;
            i=-1;
        }
    }


    for(i=1000;q[i]==0;i--){//检测第一个不是0的数字
        if(q[i]!=0){
            break;
        }
    }
    for(;i>=0;i++){
        printf("%d",q[i]);
    }
    printf(" %d",r);
    return 0;
}


/*
#include <stdio.h>
#include <string.h>


int main() {
char A[1100], Q[1100];
int B, R, i, j, length, sum;
scanf("%s", A);
scanf("%d", &B);
length = strlen(A);
sum = 0;
for(i = 0, j = 0; i < length; i ++) {
sum = 10 * sum + A[i] - '0';
if(i == 0 && sum < B && length > 1) {

} else {
Q[j ++] = sum / B + '0';
}
sum = sum % B;
}
R = sum;
Q[j] = '\0';
printf("%s %d", Q, R);
return 0;
}
*/
