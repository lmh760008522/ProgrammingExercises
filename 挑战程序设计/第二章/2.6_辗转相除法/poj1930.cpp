//���⣺������ѭ��С����������������ȷ��ѭ�������ļ�λ��Ҫ�������ĸ��С�ķ�����
/*
һ����ѭ��С����������ѭ���ڵ����ֳ���ѭ���ڵ�λ����9��ɵ����������磺 
0.3333����=3/9=1/3�� 
0.285714285714����=285714/999999��2/7. 
������ѭ��С���������磺0.24333333��������ѭ�����ֺ�ѭ���ڹ��ɵĵ�����ȥ��ѭ�����ֵĲ�ٳ���ѭ����λ����9���ϲ�ѭ�����ֵ�λ����0�����磺 
0.24333333��������=(243-24)/900=73/300 
0.9545454��������=(954-9)/990=945/990=21/22
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

//�ж�������������� 
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

//�����õ��ķ������򣬵õ�������Ϊ������ʱ���Ӻͷ�ĸ��ֵ 
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
        //�ж�С�������Ǵӵڼ�λ��ʼ���ӵڼ�λ��������ͷ��0��һλ��С������һλ),startΪ��ʼλ����endΪ����λ�� 
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
        for(int i=start;i<=end;i++){//������ӵ�iλ��ʼΪѭ����ʱ����С����Ӧ�ķ���ֵ�����ж��ڴ�����·�ĸ�Ƿ�ȡ��Сֵ 
            int fz=0,fm=0;//fzΪ����ֵ��fmΪ��ĸֵ
            /*
                һ����ѭ��С����������ѭ���ڵ����ֳ���ѭ���ڵ�λ����9��ɵ����������磺 
                0.3333����=3/9=1/3�� 
                0.285714285714����=285714/999999��2/7. 
                ������ѭ��С���������磺0.24333333��������ѭ�����ֺ�ѭ���ڹ��ɵĵ�����ȥ��ѭ�����ֵĲ�ٳ���ѭ����λ����9���ϲ�ѭ�����ֵ�λ����0�����磺 
                0.24333333��������=(243-24)/900=73/300 
                0.9545454��������=(954-9)/990=945/990=21/22
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
            //�жϷ�ĸ�Ƿ�ȡ��Сֵ 
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

