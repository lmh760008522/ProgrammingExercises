#include<stdio.h>
#include<math.h>
//?两段程序一样，但是i结果不一样不知道为什么
int main(){
    char a[11],b[11];
    int a0,b0;
    int i,count;
    int ans1=0,ans2=0;
    scanf("%s %d %s %d",a,&a0,b,&b0);
    count=0;
    for(i=0;a[i]!='\0';i++){
        if(a[i]==a0+48){
            ans1+=pow(10,count)*a0;
            printf("ans1:%d %d %lf\n",count,ans1,pow(10,count)*a0);
            count++;
        }
    }
    count=0;
     for(i=0;b[i]!='\0';i++){
        if(b[i]==b0+48){
            ans2+=pow(10,count)*b0;
            printf("ans2:%d %d %lf\n",count,ans2,pow(10,count)*b0);
            count++;
        }
    }
    printf("%d",ans1+ans2);
    return 0;
}


/*
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::string a, b;
    char a1, b1;
    std::cin>>a>>a1>>b>>b1;
    int num1 = 0, num2 = 0;
    for(int i=0; i<(int)a.length(); ++i)
    {
        if(a1 == a[i])
            num1++;
    }
    for(int i=0; i<(int)b.length(); ++i)
    {
        if(b1 == b[i])
            num2++;
    }
    //std::cout<<num1<<" "<<num2<<std::endl;
    int p = a1 - '0';
    int q = b1 - '0';
    //std::cout<<p<<" "<<q<<std::endl;
    long n = 0, m = 0;
    for(int i=0; i<num1; ++i)
    {
        long x = 1;
        for(int j = 0; j < i; ++j)
            x *= 10;
        n += p * x;
    }
    for(int i=0; i<num2; i++)
    {
        long x = 1;
        for(int j = 0; j < i; ++j)
            x *= 10;
        m += q * x;
    }
    std::cout<<n+m<<std::endl;
    return 0;
}
*/
