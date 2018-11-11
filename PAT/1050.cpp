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
			printf("%d", helical[i][0]);//�������Ҳ���� 
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
�㷨��
�㷨��ʼ��
����N������gap�����洢m-n��
i=1��n=i��m=N��gap=m-n��
���i>sqrt(sum)����ô�����������������������һ����
���n%i==0 && gap > N/i - i����ôgap=N/i-i��m=N/i��n=i��i++�����ص��Ĳ���
����m��n�еĶ�ά���飬��СΪN�����顣
��ȡN������������������������
����circle=0������i��j��count = 0��
���circle��С�ڣ�n-1��/2���������ڶ�ʮ�˲���
i=circle��
���i����n-1-circle����������ʮ�岽��
��ά����[circle][i]=����[count++]��
i++���ص���ʮ������
j=circle+1��
���j����m-1-cirlce����������ʮ�Ų���
��ά����[j][n-1-circle]=����[count++]��
j++���ص���ʮ������
i=n-1-circle��
���iС���㣬�������ڶ�ʮ������
��ά����[m-1-circle][i]=����[count++]��
i--���ص��ڶ�ʮ����
���n-1-circle<=circle���������ڶ�ʮ�߲���
j=m-1-circle-1��
���j������circle���������ڶ�ʮ�߲���
��ά����[j][circle]=����[count++]��
j--���ص��ڶ�ʮ�Ĳ���
circle++���ص��ھŲ���
���������鵽��Ļ��ȥ��
�㷨������
ʱ�临�Ӷȣ�O(nlogn�����ռ临�Ӷȣ�O(n)��ע�⣺������Ȧʱ���ܸ���֮ǰ�ĸ�ֵ�������ݡ��޸�scanf_s�����Ϳ�����PAT�����С�
*/ 
