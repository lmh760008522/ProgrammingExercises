//21/11/18 19:48   21/11/18 19:58    21/11/18 20:29  21/11/18 20:44
//先将一堆不同的（distinct）正数 放进一个哈希表
//从哈希表中找到另个正数序列 ，并输出平均寻找时间（即比较的数量）
//哈希表定义：H(key) = key%T , T = 哈希表的最大值
//解决冲突的方法：二次探测法（仅具有正增量） ——Quadratic probing
//注：表大小最好是素数(prime) ，假如给的最大值不是素数，那么找到比最大值大的最小的素数
#include<stdio.h>
#include<math.h>

int hash_table[10005];
int msize, n, m;

bool isprime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main(){
	scanf("%d %d %d", &msize, &n, &m);
	
	while(!isprime(msize)){
		msize++;
	}
	
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(hash_table[x % msize] == 0){
			hash_table[x % msize] = x;
		}else{
			bool flag = false;
			for(int k =1; k < msize; k++){
				if( hash_table[(x + k*k) % msize] == 0){
					hash_table[(x + k*k) % msize] = x;
					flag = true;
					break;
				}
			}
			if( flag == false){//未成功插入 
				printf("%d cannot be inserted.\n", x);
			}
		}
	}
	int sum = 0;
	for(int i=0;i<m;i++){
		int x;
		scanf("%d", &x);
		for(int k = 0; k <= msize; k++){
			sum++;
			if( hash_table[(x + k*k) % msize] == x || hash_table[(x + k*k) % msize] == 0){//找到了或不存在 
				break;
			}
		}
	}
	printf("%.1f\n", double(sum)/m);
	return 0;
} 

//21/11/18 20:45 部分正确 
