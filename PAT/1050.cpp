#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int cmp(const void* v1, const void* v2);
int main(void) {
	int sum, m, n, i, j, count, circle, gap;
	int* array;
	int** helical;
	scanf("%d", &sum);
	if (sum) {
		array = (int*)calloc(sum, sizeof(int));
		m = sum;
		n = 1;
		gap = m - n;
		i = 2;
		j = (int)sqrt(sum);
		while (i <= j) {
			if (sum%i == 0 && sum / i - i < gap) {
				m = sum / i;
				n = i;
				gap = sum / i - i;
			}
			i++;
		}
		
		helical = (int**)calloc(m, sizeof(int*));
		for (i = 0; i < m; i++) {
			helical[i] = (int*)calloc(n, sizeof(int));
		}
		for (i = 0; i < sum; i++) {
			scanf("%d", array + i);
		}
		qsort(array, sum, sizeof(int), cmp);
		circle = 0;
		count = 0;
		while (circle <= (n - 1) / 2) {
			for (i = circle; i < n - circle; i++) {
				helical[circle][i] = array[count++];
			}
			for (i = circle + 1; i < m - circle; i++) {
				helical[i][n - 1 - circle] = array[count++];
			}
			for (i = n - 2 - circle; i >= circle; i--) {
				helical[m - 1 - circle][i] = array[count++];
			}
			if (n - 1 - circle > circle) {
				for (i = m - 2 - circle; i >= circle + 1; i--) {
					helical[i][circle] = array[count++];
				}
			}
			circle++;
		}
 
		for (i = 0; i < m; i++) {
			printf("%d", helical[i][0]);//这个方法也不错 
			for (j = 1; j < n; j++) {
				printf(" %d", helical[i][j]);
			}
			if (i != m - 1) {
				putchar('\n');
			}
		}
		
		//FREE 
		free(array);
		for (i = 0; i < m; i++) {
			free(helical[i]);
		}
		free(helical);
	}
	else {
		putchar('\0');
	}
	return 0;
}
int cmp(const void* v1, const void* v2) {
	return *((int*)v2) - *((int*)v1);
}
/*
算法：
算法开始。
读入N，声明gap用来存储m-n。
i=1。n=i。m=N。gap=m-n。
如果i>sqrt(sum)，那么就跳到第六步。否则进行下一步。
如果n%i==0 && gap > N/i - i，那么gap=N/i-i，m=N/i，n=i。i++。跳回第四步。
设置m行n列的二维数组，大小为N的数组。
读取N个正整数，并不递增地排序。
声明circle=0，声明i，j，count = 0。
如果circle不小于（n-1）/2，则跳到第二十八步。
i=circle。
如果i大于n-1-circle，则跳到第十五步。
二维数组[circle][i]=数组[count++]。
i++。回到第十二步。
j=circle+1。
如果j大于m-1-cirlce，则跳到第十九步。
二维数组[j][n-1-circle]=数组[count++]。
j++。回到第十六步。
i=n-1-circle。
如果i小于零，则跳到第二十三步。
二维数组[m-1-circle][i]=数组[count++]。
i--。回到第二十步。
如果n-1-circle<=circle，则跳到第二十七步。
j=m-1-circle-1。
如果j不大于circle，则跳到第二十七步。
二维数组[j][circle]=数组[count++]。
j--，回到第二十四步。
circle++，回到第九步。
输出这个数组到屏幕上去。
算法结束。
时间复杂度：O(nlogn），空间复杂度：O(n)。注意：螺旋绕圈时不能覆盖之前的赋值过的数据。修改scanf_s函数就可以在PAT上运行。
*/ 
