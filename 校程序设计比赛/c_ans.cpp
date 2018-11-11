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

 /* 任务分配
描述:现有n个任务,要交给A和B完成。每个任务给A或给B完成，所需的时间分别为ai和bi。
问他们完成所有的任务至少要多少时间。 
 我们可以用p(i,j)表示前i个任务可由A在j时间内且B在p(i,j)时间内完成。 
 递推方程也容易修改了：第i个任务是由第i-1个任务推出来的，那么第i个任务可由A或B机完成： 
 如果由A机完成，则有：p(i,j) = p(i-1,j-Ai) (B机时间不变） 
如果由B机完成，则有：p(i, j) = p(i-1,j)+ Bi (A机时间不变） 
  */
int  solve(){
  int sum=0;f[0][0]=0;
  for(int i=1;i<=n;++i){
    sum+=a[i];
    for(int j=0;j<=sum;++j){
      f[i][j]=f[i-1][j]+b[i];//有b完成
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
