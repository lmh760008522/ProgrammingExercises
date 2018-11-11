#include<stdio.h>
#include<map>
#include<string>
#include<utility>
#include<vector>
/*
    PAT的时间限制一般没有那么严格，但是这道题很明显是要求用hash方法做，
    并且坑定了使用stl中的map方法。
    有人说是map中使用了string==来查找，造成超时，但经过创建class A,重载==
    和<,发现结果仍是最后一个测试点超时。

    map内部是通过平衡二叉树完成查找的，而hash是通过直接地址映射完成，是常量级的
    总结: 
    1.string cin cout均是耗时操作
    2.map中使用==进行判断，string的==较为复杂,最后一个测试点超时
    3.vector.size()返回的是unsinged int类型,也就是说支持2^32个元素
     */
using namespace std;
int main(){
	vector<pair(string, vector<int>)> a;
	int n,k;
	int id,num;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&id,&num);
		for(int j=0;j<num;j++){
			scanf("%s");
		}
	}
	return 0
}
