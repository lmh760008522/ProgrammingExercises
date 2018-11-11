//题意：把无限循环小数变最简分数，但不确定循环节是哪几位，要求输出分母最小的分数。
/*
一，纯循环小数化分数：循环节的数字除以循环节的位数个9组成的整数。例如： 
0.3333……=3/9=1/3； 
0.285714285714……=285714/999999＝2/7. 
二，混循环小数：（例如：0.24333333……）不循环部分和循环节构成的的数减去不循环部分的差，再除以循环节位数个9添上不循环部分的位数个0。例如： 
0.24333333…………=(243-24)/900=73/300 
0.9545454…………=(954-9)/990=945/990=21/22
*/
#include<iostream>
#include<math.h>
using namespace std;
int gcd(int a,int b)
{
	if(!a)
		return b;
	return gcd(b%a,a);
}
int main()
{
	char str[100];	int num,k,all,a,b,i,j,mina,minb,l;
	while(cin>>str&&strcmp(str,"0"))
	{
		mina=minb=1000000000;
		for(i=2,all=0,l=0;str[i]!='.';i++)
		{
			all=all*10+str[i]-48;
			l++;
		}
		for(num=all,k=1,i=1;i<=l;i++)
		{
			num/=10;
			k*=10;
			a=all-num;
			b=(int)pow(10.0,l-i)*(k-1);
			j=gcd(a,b);
			if(b/j<minb)
			{
				mina=a/j;	minb=b/j;
			}
		}
		cout<<mina<<'/'<<minb<<endl;
	}
	return 0;
}

/*
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
string str;

//判断两数的最大公因数 
int gcd(int x,int y){
    int ret;
    if(y==0){
        ret=x;
    }else if(x<y){
        ret=gcd(y,x);
    }else{
        ret=gcd(y,x%y);
    }
    return ret;
}

//将所得到的分数化简，得到当分数为最简分数时分子和分母的值 
pair<int,int> jh(int x,int y){
    int li=gcd(x,y);
    if(li==1){
        return make_pair(x,y);
    }else{
        return jh(x/li,y/li);
    }
}

int main(){
    while(cin>>str&&str.size()!=1){
        int fmmin=99999999;
        int fzmin;
        int yjr=0;int start,end,fxhj;
        //判断小数部分是从第几位开始，从第几位结束（开头的0算一位，小数点算一位),start为起始位数，end为结束位数 
        for(int i=0;i<str.size();i++){
            if(yjr==0&&str[i]=='.'){
                start=i+1;
                yjr=1;
            }
            if(yjr==1&&str[i+1]=='.'){
                end=i;
            }
        }
        end-=2;
        for(int i=start;i<=end;i++){//求出当从第i位开始为循环节时，该小数对应的分数值，并判断在此情况下分母是否取最小值 
            int fz=0,fm=0;//fz为分子值，fm为分母值
            /*
                一，纯循环小数化分数：循环节的数字除以循环节的位数个9组成的整数。例如： 
                0.3333……=3/9=1/3； 
                0.285714285714……=285714/999999＝2/7. 
                二，混循环小数：（例如：0.24333333……）不循环部分和循环节构成的的数减去不循环部分的差，再除以循环节位数个9添上不循环部分的位数个0。例如： 
                0.24333333…………=(243-24)/900=73/300 
                0.9545454…………=(954-9)/990=945/990=21/22
            */ 
            for(int j=i;j<=end;j++){
                fz=fz*10+(str[j]-'0');
                fm=fm*10+9;
            }
            int plus=0;
            if(i>start){
                for(int j=start;j<i;j++){
                    plus=plus*10+(str[j]-'0');
                    fm=fm*10;
                }
                int qian=plus;
                for(int j=i;j<=end;j++){
                    qian=qian*10;
                }
                qian=fz+qian;
                fz=qian-plus;
            }
            //判断分母是否取最小值 
            if(jh(fz,fm).second<fmmin){
                fmmin=jh(fz,fm).second;
                fzmin=jh(fz,fm).first;
            }
        }
        printf("%d/%d\n",fzmin,fmmin);
    }
    return 0;
}
*/

