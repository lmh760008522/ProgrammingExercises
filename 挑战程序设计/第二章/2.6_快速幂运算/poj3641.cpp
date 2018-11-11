#include <iostream>
using namespace std;
typedef unsigned long long ull; 
ull a,p;
bool testPrime(ull x)
{
    for(ull i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
ull mpow(ull x,ull n,ull mod)
{
    ull res=1;
    while(n>0)
    {
        if(n&1)
        {
            res=(res*x)%mod;
        }
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
int main()
{
    while(cin>>p>>a)
    {
        if(a==0&&p==0)    break;
        if(testPrime(p))
        {
            cout<<"no"<<endl;
        }            
        else
        {
            if(mpow(a,p,p)==a%p)
            {
                cout<<"yes"<<endl;
            }    
            else
            {
                cout<<"no"<<endl;
            }
        }
    }
    return 0;
}
