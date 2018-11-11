//描述
//笨小熊的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！ 
//这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小熊就认为这是个Lucky Word，这样的单词很可能就是正确的答案。
//
//输入
//第一行数据N(0<N<100)表示测试数据组数。
//每组测试数据输入只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。
//输出
//每组测试数据输出共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”； 
//第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0
#include<stdio.h>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
	int n,count[26],i,max,min;
	string s;
	scanf("%d",&n);
	while(n>0){
		s="";
		max=0;
		min=100;
		for(i=0;i<26;i++){                       //替换成int count[26]={0} 
			count[i]=0;
		}
		cin>>s;
		//cout<<s.length()<<endl;
		for(i=0;i<s.length();i++){
			count[s[i]-97]++;
			if(count[s[i]-97]<min){
				min=count[s[i]-97];                         //现成函数调用 
			
			}
			if(count[s[i]-97]>max){
				max=count[s[i]-97];                        //现成函数调用  
			}
		}
		if((max-min)==1||(max-min)==2){                     //1\2特殊考虑 
			printf("Lucky Word\n%d\n",max-min);
		}else if((max-min)==0){
			printf("Lucky Word\n%d\n",max-min);
		}
		else{
			for(i=2;i<(max-min);i++){
				if((max-min)%i==0){
					break;
				}
			}
			if(i==(max-min)){
				printf("Lucky Word\n%d\n",max-min);
			}
			else{
				printf("No Answer\n%d\n",0);
			}
		}
		n--;
	}
} 

/*
 
#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

bool isPrime(int n)
{
	if(n==0) return false;
	if(n==1) return false;
	if(n==2) return true;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0) return false;
	}
	return true;

}
int min_e(int *p,int *q)
{
	int m=1000;
	for(int* i=p;i!=q;i++)
	{
		if(*i<m && *i!=0) m=*i;
	}
	return m;
}
int main()
{
		int n;
	string str;
	cin>>n;
	while(n--)
	{
		int count[26]={0};
		cin>>str;
		for(int i=0;i!=str.size();++i)
		{
			++count[str[i]-'a'];
		}
		int nn=*max_element(count,count+26)-min_e(count,count+26);
		if(isPrime(nn)) cout<<"Lucky Word"<<endl<<nn<<endl;
		else cout<<"No Answer"<<endl<<0<<endl;

	}
}        
*/
