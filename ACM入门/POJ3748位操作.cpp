/* POJ3748 Î»²Ù×÷ */
 
#include <iostream>
#include <bitset>
#include <stdio.h>
 
using namespace std;
 
int main()
{
    int r, x, y;
 
    while(scanf("%x,%d,%d", &r, &x, &y ) != EOF) {
        bitset<32> bitop(r);
        bitop.set(x, 0) ;
        bitop.set(y, 1) ;
        bitop.set(y - 1, 1) ;
        bitop.set(y - 2, 0) ;
        printf("%x\n", (unsigned int)bitop.to_ulong()) ;
    }
 
    return 0;
}

/*
C³ÌÐò 
 
#include <stdio.h>
 
int main(void)
{
    int r, x, y;
 
    while(scanf("%x,%d,%d", &r, &x, &y ) != EOF) {
        r &= ~(1 << x);
 
        r |= (1 << (y-1)) | (1 << y);
        r &= ~(1 << (y-2));
 
        printf("%x\n", r);
    }
 
    return 0;
}

*/

