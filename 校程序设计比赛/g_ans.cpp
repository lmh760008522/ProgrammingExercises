#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int v[7];
int main(int argc, const char * argv[]) {
    int a[3];
    while (scanf("%d%d%d",&a[0],&a[1],&a[2])!=EOF) {
        memset(v, 0, sizeof(v));
        for (int i = 0; i < 3; i++) {
            v[a[i]]=1;
        }
        if (v[1] == 0 && v[6]==0)
            printf("1\n");
        else if (v[2]==0 && v[5]==0)
            printf("2\n");
        else if (v[3]==0 && v[4]==0)
            printf("3\n");
        else
            printf("0\n");
        
    }
    return 0;
}


