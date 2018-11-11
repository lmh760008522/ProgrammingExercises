#include <cstdio>  
      
int solve(int x)  
{  
    if(x % 8 == 0 || x % 8 == 1)  
        return x;  
    if(x % 8 == 2 || x % 8 == 3)  
        return 2;  
    if(x % 8 == 4 || x % 8 == 5)  
        return x + 2;  
    return 0;  
}  
      
int main()  
{  
    int T;  
    scanf("%d", &T);  
    while(T --)  
    {  
        int l, r;  
        scanf("%d %d", &l, &r);  
        printf("%d\n", (solve(r) ^ solve(l - 1)));  
    }     
}  
