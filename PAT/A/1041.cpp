//��һ�ַ�������������λ��i=x[i]������������ 

#include <cstdio>
using namespace std;

#define max 55
int main() {
    int cnt;
    scanf("%d", &cnt);
    int end[max], scan[max],cha[max];
    for(int i = 1; i < max; i++) {
        scanf("%d", &scan[i]);
        cha[i]=scan[i];
    }
    while(cnt-1>0){
    	for(int i=1;i<max;i++){
    		//printf("%d -- %d --",cha[i],scan[scan[i]]);
    		cha[i]=scan[scan[i]];
    		//printf(" %d\n",cha[i]);
		}
		cnt--;
	}
	/*
	printf("scan:");
	for(int i=1;i<max;i++){
		printf("%d ",cha[i]);
	}
	printf("\n");
	*/
	for(int i=1;i<max;i++){
		end[cha[i]]=i;
	}
	
	//��ӡ���ص㣡 
	char c[6] = {"SHCDJ"};
    for(int i = 1; i < 55; i++) {
        end[i] = end[i] - 1;
        printf("%c%d", c[end[i]/13], end[i]%13+1);
        if(i != 54) printf(" ");
    }
    return 0;
}
