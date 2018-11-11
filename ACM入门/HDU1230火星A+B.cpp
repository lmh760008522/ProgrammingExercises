#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
	int prime[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,87,97,101};
	char s1[50], s2[50];
	while( scanf("%s %s\n", s1, s2) != EOF){
		if( strcmp(s1,"0") == 0 && strcmp(s2,"0") == 0){
			break;
		}
		char ans[50];
		int len1 = strlen(s1), len2 = strlen(s2);
		int c=0;//进位 
		int k=0;//prime指针 
		int i;//ans指针 
		for(i = 0; i<min(strlen(s1), strlen(s2)); i++){
			if(s1[len1-1] == ',' && s2[len2-1] == ','){
				ans[i] = ',';
			}
			ans[i] = s1[len1-1] + s2[len2-1] -'0' +c;
			if(ans[i]-'0' >= prime[k]){
				c=ans[i]-'0'-prime[k];
				ans[i] = '0';
				k++;
			} 
			len1--, len2-- ;
		}
		if(len1 == 0){
			for(int j=len2-1; j>=0; j--){
				ans[i++] = s2[j];
			}
		}else if(len2 == 0){
			for(int j=len1-1; j>=0; j--){
				ans[i++] = s1[j];
			}
		}
		
		//输出 
		for(int j=strlen(ans)-1; j>=0; j++){
			printf("%c", ans[j]);
		} 
	}
	return 0;
} 

/*

输入优化
for(;;) {
            scanf("%d%c", &a[i], &c);
            if(c == ' ')
                break;
            else
                i++;
        } 
*/


/*
答案
 
#include <stdio.h>
#include <memory.h>
 
#define MAXN    30
 
int primes[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int a[MAXN], b[MAXN], sum[MAXN], acount, bcount, count;
char c;
 
int main(void)
{
    int i, j;
 
    while(1) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(sum, 0, sizeof(sum));
 
        i = 0;
        for(;;) {
            scanf("%d%c", &a[i], &c);
            if(c == ' ')
                break;
            else
                i++;
        }
        acount = i;
 
        i = 0;
        for(;;) {
            scanf("%d%c", &b[i], &c);
            if(c == '\n')
                break;
            else
                i++;
        }
        bcount = i;
 
        if(acount == 0 && bcount == 0 && a[0] == 0 && b[0] == 0)
            break;
 
        count = (acount > bcount) ? acount : bcount;
 
        for(i=acount, j=0; i >= 0; i--, j++)
            sum[j] += a[i];
 
        for(i=bcount, j=0; i >= 0; i--, j++)
            sum[j] += b[i];
 
        for(i=0; i<=count; i++)
            if(sum[i] >= primes[i]) {
                sum[i] -= primes[i];
                sum[i+1]++;
            }
        if(sum[count+1])
            count++;
 
        for(i=count; i>0; i--)
            printf("%d,", sum[i]);
        printf("%d\n", sum[0]);
    }
 
    return 0;
}
 
*/ 
