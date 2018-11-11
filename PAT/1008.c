#include<stdio.h>
int main(){
    int n,m,i,count=0;
    char s[200];
    scanf("%d %d\n",&n,&m);//或去掉\n 加上getchar();
    gets(s);
    for(i=(2*n-2*m);i<(2*n-1);i=i+2){
        printf("%c",s[i]);
        count++;
        if(count<n){
            printf(" ");
        }
    }
    for(i=0;i<(2*n-2*m);i=i+2){
        printf("%c",s[i]);
        count++;
        if(count<n){
            printf(" ");
        }
    }
    return 0;
}

/*
#include <stdio.h>
int a[100];
void reverse(int *a, int m, int n){
	for (int i = m; i <= (m + n) / 2; i++){
		int tmp = a[i];
		a[i] = a[m + n - i];
		a[m + n - i] = tmp;
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	m %= n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	reverse(a, 0, n-m-1);
	reverse(a, n-m, n-1);
	reverse(a, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d%s", a[i], (i-n+1?" ":"\n"));
	return 0;
}
*/
