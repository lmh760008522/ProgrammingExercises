#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 89080 // 1000001范围内所有prime数个数上限，可事先程序计算
#define Maxx 1000010 // 4n+1数最大为1000001
int Sum[Maxx]; // 求和数组
int prime[Max]; // 保存prime数
bool flag[Maxx]; // 判断是否为prime数
int num,h; // num为prime数个数
void prime_table(int n){// 筛法求prime数，代码几乎后筛法求素数一样。因为思想一致
	int i,j,pivot=0;
	memset(flag,0,sizeof(flag)); // 全部初始化为不是prime数
	prime[pivot++]=5;
	flag[5]=true; //筛法核心代码
	for(i=9;i<=n;i+=4){
		bool trag=true;
		for(j=0;prime[j]*prime[j]<=i;j++)
			if(i%prime[j]==0)
				trag=false;
		if(trag){ //若为prime数，则flag设置为true
			prime[pivot++]=i;
			flag[i]=true;
		}
	}
	num=pivot; // prime数个数
}
void Get_num(int h){ // 判断是否为semi-prime数，再次过程中打第二张表
	int i,j;
	Sum[1]=0;//1——1范围内semi-prime个数为0
	for(i=5;i<=h;i+=4){ // 第二个4n+1数为5，第三个为9，  13 ，……
		if(flag[i]){ // 剪枝，若为prime数，则必定不是semi-prime数，Sum[i]=Sum[i]=Sum[i-4];
			Sum[i]=Sum[i-4];
			continue;
		}
		j=0;
		bool trag=false; // 设置标记 ，注意j<num条件。若没有该条件，则可能因为j>=num而产生不可预知的结果（死循环）
		while(j<num && prime[j]*prime[j]<=i){ // 剪枝关键：两数因子中较小的平方要小于等于乘积数。
			if(i%prime[j]==0 && flag[i/prime[j]]){
				trag=true;
				break;
			}
			j++;
		}
		if(trag) // 若为semi-prime数，则Sum[i]=Sum[i-4]+1;
			Sum[i]=Sum[i-4]+1;
	    else
			Sum[i]=Sum[i-4];
	}
}
int main(){
	prime_table(1000001); // 打第一张表
	Get_num(1000001); // 打第二张表
	while(scanf("%d",&h),h) 
		printf("%d %d\n",h,Sum[h]); // 直接输出
	return 0;
}
