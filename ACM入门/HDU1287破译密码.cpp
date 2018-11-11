//思路：试探法寻找密码用大写字母是需要找到一个字母x，满足对于所有数据计算结果都为大写字母。 
#include<stdio.h>
#include<ctype.h>
int main(){
	int n;
	int x;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		
		int v[50];
		for(int j=0; j<n; j++)
            scanf("%d", &v[j]);
 
        // 试探法寻找加密用大写字母
        for(int k='A'; k<='Z'; k++) {
        	int j;
            for(j=0; j<n; j++) {
                if(!isupper(v[j] ^ k))
                    break;
            }
            if(j == n) {
                x = k;
                break;
            }
        }
 
        // 使用加密用大写字母x解密
        for(int j=0; j<n; j++) {
            putchar(v[j]^x);
        }
        putchar('\n');
	}
	return 0;
}
