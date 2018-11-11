#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int> > v(1); 

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int size = n;
		for(int j=0;j<n;j++){
			v.push_back(v[j]);
			v.back().push_back(i);
			for(int k=0;k<v[j].size();k++){
				printf("%d",v[j][k]);
			}
			printf("\n");
		}
	}
	
	return 0;
}  
/*
比如对于题目中给的例子[1,2,3]来说，最开始是空集，那么我们现在要处理1，就在空集上加1，为[1]，现在我们有两个自己[]和[1]，下面我们来处理2，我们在之前的子集基础上，每个都加个2，可以分别得到[2]，[1, 2]，那么现在所有的子集合为[], [1], [2], [1, 2]，同理处理3的情况可得[3], [1, 3], [2, 3], [1, 2, 3], 再加上之前的子集就是所有的子集合了，代码如下：
*/
