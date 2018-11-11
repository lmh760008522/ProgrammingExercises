
/*
首先看一个关于质数分布的规律：大于等于5的质数一定和6的倍数相邻。例如5和7，11和13,17和19等等；

证明：令x≥1，将大于等于5的自然数表示如下：
······ 6x-1，6x，6x+1，6x+2，6x+3，6x+4，6x+5，6(x+1），6(x+1)+1 ······
可以看到，不在6的倍数两侧，即6x两侧的数为6x+2，6x+3，6x+4，
由于2(3x+1)，3(2x+1)，2(3x+2)，所以它们一定不是素数，再除去6x本身，
显然，素数要出现只可能出现在6x的相邻两侧。这里有个题外话，关于孪生素数，
有兴趣的道友可以再另行了解一下，由于与我们主题无关，暂且跳过。
这里要注意的一点是，在6的倍数相邻两侧并不是一定就是质数。
此时判断质数可以6个为单元快进，即将方法（2）循环中i++步长加大为6，
加快判断速度，原因是，假如要判定的数为n，则n必定是6x-1或6x+1的形式，
对于循环中6i-1，6i，6i+1,6i+2，6i+3，6i+4，其中如果n能被6i，6i+2，6i+4整除，
则n至少得是一个偶数，但是6x-1或6x+1的形式明显是一个奇数，故不成立；
另外，如果n能被6i+3整除，则n至少能被3整除，但是6x能被3整除，故6x-1或6x+1（即n）
不可能被3整除，故不成立。综上，循环中只需要考虑6i-1和6i+1的情况，即循环的步长可以定为6，
每次判断循环变量k和k+2的情况即可，理论上讲整体速度应该会是方法（2）的3倍。代码如下：
*/
#include<cstdio>
#include<cmath>
bool prime( long long  num ){
	if(num==1) return false;
    //两个较小数另外处理
    if(num ==2|| num==3 )  return true;
    //不在6的倍数两侧的一定不是质数
    if(num %6!= 1&&num %6!= 5)  return false ;
    long tmp =sqrt( num);
    //在6的倍数两侧的也可能不是质数
    for(int i= 5;i <=tmp; i+=6 )
        if(num %i== 0||num %(i+ 2)==0 )
            return false ;
    //排除所有，剩余的是质数
    return true ;
}

int main(){
	int t;
	scanf("%d",&t);
	bool flag;
	int time;
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		flag=false;
		time=0;
		while(time++ <k){
			if( prime(n) ){
				time=time-1;
				flag=true;
				break;
			}else if( prime(n-1) || prime(n+1)	){
				flag=true;
				break;
			}else{
				n=n*2;
			}
		}
	}
	if(flag){
		printf("BJ gets the pretty meizi with %d minutes!\n",time);
	}else{
		printf("Poor BJ, single all his life!\n");
	}
	return 0;
} 

//思路错误
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
//0 1 1 0 1 0 1 0 0 0  1  0  1  0  0  0  1  0  1  0  0  0  1  0  0  0  1  0
