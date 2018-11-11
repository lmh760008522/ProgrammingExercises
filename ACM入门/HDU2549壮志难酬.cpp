#include<stdio.h>
int main(){
	int t;
	for(int i=0; i<t; i++){
		char c[105];
		int n;
		scanf("%s %n", c, &n);
		int t=0;
		while(c[t]!='.'){
			t++;
		}
		printf("%c\n", c[t+n]);
	}
	return 0;
}

/* 
优化：
这个题需要注意的一点是，给定的数小数点后只有m位，输入的n>m时，则第n位为0。

  其他都是输入输出流处理问题。小数点前的各位就不需要存储了，这样处理起来要容易许多。 
 
#include <stdio.h>
 
int main(void)
{
    int t, count, n;
    char s[10], c;
 
    scanf("%d", &t);
    getchar();
    while(t--) {
        // 跳过小数点之前的字符
        while((c=getchar()) != '.');
 
        // 小数点之后的字符放入数组s中，并计数小数点后的位数
        count = 0;
        while((c=getchar()) != ' ')
            s[count++] = c;
 
        // 读入n
        scanf("%d", &n);
        getchar();
 
        // 输出结果
        if(n>count)
            printf("0\n");
        else
            printf("%c\n", s[n-1]);
    }
 
    return 0;
}

*/
