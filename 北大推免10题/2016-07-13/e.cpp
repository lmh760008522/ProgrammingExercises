#define MAX_LEN 255

#include<stdio.h>
#include<string.h>

char last[MAX_LEN+1]="",now[MAX_LEN+1]="";
int n,ans=0,l1=0,l2=0,len=0;

int main()
{
    scanf("%d",&n); 
    while (n--)
    {
        strcpy(last,now);
        l1=l2;
        scanf("%s\n",&now);
        l2=strlen(now);
        len=0;
        for (int i=0;i<l1 && i<l2;i++)
        {
            if (now[i]!=last[i])
                break;
            len++;
        }
        ans+=l2-len+1;
    }
    printf("%d\n",ans-1);
    return 0;
}
