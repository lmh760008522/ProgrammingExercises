//����
//��С�ܵĴʻ�����С������ÿ����Ӣ��ѡ�����ʱ�򶼺�ͷ�ۡ��������ҵ���һ�ַ�����������֤���������ַ���ȥѡ��ѡ���ʱ��ѡ�Եļ��ʷǳ��� 
//���ַ����ľ����������£�����maxn�ǵ����г��ִ���������ĸ�ĳ��ִ�����minn�ǵ����г��ִ������ٵ���ĸ�ĳ��ִ��������maxn-minn��һ����������ô��С�ܾ���Ϊ���Ǹ�Lucky Word�������ĵ��ʺܿ��ܾ�����ȷ�Ĵ𰸡�
//
//����
//��һ������N(0<N<100)��ʾ��������������
//ÿ�������������ֻ��һ�У���һ�����ʣ�����ֻ���ܳ���Сд��ĸ�����ҳ���С��100��
//���
//ÿ�����������������У���һ����һ���ַ�������������ĵĵ�����Lucky Word����ô�����Lucky Word�������������No Answer���� 
//�ڶ�����һ��������������뵥����Lucky Word�����maxn-minn��ֵ���������0
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
		for(i=0;i<26;i++){                       //�滻��int count[26]={0} 
			count[i]=0;
		}
		cin>>s;
		//cout<<s.length()<<endl;
		for(i=0;i<s.length();i++){
			count[s[i]-97]++;
			if(count[s[i]-97]<min){
				min=count[s[i]-97];                         //�ֳɺ������� 
			
			}
			if(count[s[i]-97]>max){
				max=count[s[i]-97];                        //�ֳɺ�������  
			}
		}
		if((max-min)==1||(max-min)==2){                     //1\2���⿼�� 
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
