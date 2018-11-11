#include<stdio.h>
#include<string.h>
#include<string> 
#include<algorithm>

using namespace std;
#define TAB "|     "
int cases=1;
char str[35];
bool isFinish=false;

void deal(int tab_num)
{
    string file_name[35];
    int file_num=0;
    scanf("%s",str);
    if (tab_num==0 && str[0]!='#')
    {
        if (cases>1)
            printf("\n");
        printf("DATA SET %d:\n",cases);
        printf("ROOT\n");
    }
    while (true)
    {
        if (str[0]=='*' || str[0]==']')
            break;
        else if (str[0]=='#'){
            isFinish=true;
            return;
        }else if (str[0]=='f')
            file_name[file_num++]=str;
        else if (str[0]=='d')
        {
            for (int i=0;i<tab_num+1;i++)
                printf("%s",TAB);
            printf("%s\n",str);
            deal(tab_num+1); 
        }
        scanf("%s",str);
    }
    sort(file_name,file_name+file_num);
    for (int i=0;i<file_num;i++)
    {   
        for (int j=0;j<tab_num;j++)
            printf("%s",TAB);
        printf("%s\n",file_name[i].c_str());
    }
    return;
}

int main()
{
    //freopen("output.txt","w",stdout);
    while (!isFinish)
    {
        deal(0);
        cases++;
    }
    return 0;
}
