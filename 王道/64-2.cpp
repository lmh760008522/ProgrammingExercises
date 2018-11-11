#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char s1[10],s2[10];

int isOK(int n)
{
        int m;
        sprintf(s1,"%d",n);
        sprintf(s2,"%d",n*n);
        sscanf(s2+strlen(s2)-strlen(s1),"%d",&m);
        cout<<s2<<" "<<s2+strlen(s2)-strlen(s1)<<" "<<strlen(s2)<<" "<<m;
        return n==m;
}

int main()
{
        int n;
        while(scanf("%d",&n)!=EOF)
        {
                if(isOK(n))printf("Yes!\n");
                else printf("No!\n");
        }
        return 0;
}
