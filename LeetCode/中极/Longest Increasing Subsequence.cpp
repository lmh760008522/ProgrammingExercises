#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int a[8]={10, 9, 2, 5, 3, 7, 101, 18};
	int n=8;
	int dp[100];
	//memset(dp,1,sizeof(dp));
	for(int i=0;i<n;i++){
		dp[i]=1;
	}
	int res=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				dp[i]=max(dp[i], dp[j]+1);
			}
		}
		res=max(res,dp[i]);
	}
	printf("%d",res);
	
	
	//下面我们来看一种优化时间复杂度到O(nlgn)的解法，这里用到了二分查找法，所以才能加快运行时间哇。
	//思路是，我们先建立一个数组ends，把首元素放进去，然后比较之后的元素，如果遍历到的新元素比ends数组中的首元素小的话，
	//替换首元素为此新元素，如果遍历到的新元素比ends数组中的末尾元素还大的话，将此新元素添加到ends数组末尾(注意不覆盖原末尾元素)。
	//如果遍历到的新元素比ends数组首元素大，比尾元素小时，此时用二分查找法找到第一个不小于此新元素的位置，
	//覆盖掉位置的原来的数字，以此类推直至遍历完整个nums数组，此时ends数组的长度就是我们要求的LIS的长度，
	//特别注意的是ends数组的值可能不是一个真实的LIS，比如若输入数组nums为{4, 2， 4， 5， 3， 7}，
	//那么算完后的ends数组为{2， 3， 5， 7}，可以发现它不是一个原数组的LIS，只是长度相等而已，千万要注意这点。参见代码如下：
	
	int end[8];
	end[0]=a[0];
	int ends=0;
	for(int i=0;i<n;i++){
		if(a[i]<end[0]){
			end[0]=a[i];
		}else if(a[i]>end[ends]){
			ends++;
			end[ends]=a[i];
		}else{
			int left=0,right=ends;
			while(left<=right){
				int mid=(left+right)/2;
				if(end[mid]<a[i]){
					left=mid+1;
				}else{
					right=mid;
				}
			}
			end[right]=a[i];
		}
	}
	printf(" -- %d",ends);
	return 0;
}
