#include<iostream>
#include<cstdio>
using namespace std;
int f[21][2001];
int n,a[21],b[21];

void input(){
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>a[i]>>b[i];
  }
}

 /* �������
����:����n������,Ҫ����A��B��ɡ�ÿ�������A���B��ɣ������ʱ��ֱ�Ϊai��bi��
������������е���������Ҫ����ʱ�䡣 
 ���ǿ�����p(i,j)��ʾǰi���������A��jʱ������B��p(i,j)ʱ������ɡ� 
 ���Ʒ���Ҳ�����޸��ˣ���i���������ɵ�i-1�������Ƴ����ģ���ô��i���������A��B����ɣ� 
 �����A����ɣ����У�p(i,j) = p(i-1,j-Ai) (B��ʱ�䲻�䣩 
�����B����ɣ����У�p(i, j) = p(i-1,j)+ Bi (A��ʱ�䲻�䣩 
  */
int  solve(){
  int sum=0;f[0][0]=0;
  for(int i=1;i<=n;++i){
    sum+=a[i];
    for(int j=0;j<=sum;++j){
      f[i][j]=f[i-1][j]+b[i];//��b���
      if(j>=a[i])
        f[i][j]=min(f[i][j],f[i-1][j-a[i]]);
    }
  }
  int ans=sum+1;
  for(int i=1;i<=sum;++i)
    ans=min(ans,max(i,f[n][i]));
  return ans;
}
int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	while(t-- >0){
		input();
  		cout<<solve()<<endl;
	}
  return 0;
}
