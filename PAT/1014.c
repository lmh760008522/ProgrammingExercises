#include<stdio.h>
#include<string.h>

//´ð°¸´íÎó£¿£¿£¿why£¿£¿£¿
int main(){
    char a[60],b[60],c[60],d[60];
    int i,j;
    int m,day,t;
    scanf("%s\n%s\n%s\n%s",a,b,c,d);
    for(i=0;i<strlen(a)&&i<strlen(b);i++){
        if((a[i]==b[i])&&a[i]>=65&&a[i]<=90){
            m=a[i];
            break;
        }
    }
    for(;i<strlen(a)&&i<strlen(b);i++){
        if((a[i]==b[i])&&((a[i]>=65&&a[i]<=78)||(a[i]>=48&&a[i]<=57))){
            day=a[i];
            if((day>=65&&day<=78)){
                day=day-54;
            }else{
                day=day-48;
            }
            break;
        }
    }
    for(i=0;i<strlen(c)&&i<strlen(d);i++){
        if((c[i]==d[i])&&((c[i]>=65&&d[i]<=90)||(c[i]>=97&&c[i]<=122))){
            t=i;
            break;
        }
    }
    switch(m){
        case 'A':printf("MON ");break;
        case 'B':printf("TUE ");break;
        case 'C':printf("WED ");break;
        case 'D':printf("THU ");break;
        case 'E':printf("FRI ");break;
        case 'F':printf("SAT ");break;
        case 'G':printf("SUN ");break;
    }
    if(day<=9){
        printf("0%d:",day);  //cout<<x/10<<x%10<<":";
    }else{
        printf("%d:",day);
    }
    if(t<=9){
        printf("0%d",t);
    }else{
        printf("%d",t);
    }
    return 0;
}

/*
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    string s2;
    string s3;
    string s4;
    cin>>s1>>s2>>s3>>s4;
    int mark=0;
    for(int i=0;i<s1.size()&&i<s2.size();i++){
            if(s1[i]==s2[i]&&(s1[i]>='A'&&s1[i]<='G')){
                      switch(s1[i]){
                         case 'A':  cout<<"MON ";break;
                         case 'B':  cout<<"TUE ";break;
                         case 'C':  cout<<"WED ";break;
                         case 'D':  cout<<"THU ";break;
                         case 'E':  cout<<"FRI ";break;
                         case 'F':  cout<<"SAT ";break;
                         case 'G':  cout<<"SUN ";break;
                                    }
                         mark=i;
                         break;
                             }

            }
      for(int j=mark+1;j<s1.size()&&j<s2.size();j++){
              if(s1[j]==s2[j]&&(s1[j]>='A' &&s1[j]<='N' || s1[j]>='0'&&s1[j]<='9')){
                 if(s1[j]>='A'&&s1[j]<='N'){
                        int x=s1[j]-'A'+10;
                        cout<<x/10<<x%10<<":";
                          }
                 else{
                  int y=s1[j]-'0';
                  cout<<y/10<<y%10<<":";
                  }
                break;
             }

              }

      for(int k=0;k<s3.size()&&k<s4.size();k++){
               if(s3[k]==s4[k]&&(s3[k]>='A'&&s3[k]<='Z'||s3[k]>='a'&&s3[k]<='z')){
                 cout<<k/10<<k%10<<endl;


              }
              }

    system("pause");
    return 0;
    }
*/
