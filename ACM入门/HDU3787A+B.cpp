/* HDU3787 A+B */
 
#include <iostream>
#include <cctype>
 
using namespace std;
 
long long myatoi(string& s)
{
    long long val;
 
    val = 0;
    for(int i=0; i<(int)s.size(); i++)
        if(isdigit(s[i]))
            val = val * 10 + s[i] - '0';
 
    if(s[0] == '-')
        val = -val;
 
    return val;
}
 
int main()
{
    string s1, s2;
    long long a, b;
 
    while(cin >> s1 >> s2) {
        a = myatoi(s1);
        b = myatoi(s2);
 
        cout << a + b << endl;
    }
 
    return 0;
}

