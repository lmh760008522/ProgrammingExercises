//˼·����̽��Ѱ�������ô�д��ĸ����Ҫ�ҵ�һ����ĸx����������������ݼ�������Ϊ��д��ĸ�� 
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
 
        // ��̽��Ѱ�Ҽ����ô�д��ĸ
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
 
        // ʹ�ü����ô�д��ĸx����
        for(int j=0; j<n; j++) {
            putchar(v[j]^x);
        }
        putchar('\n');
	}
	return 0;
}
