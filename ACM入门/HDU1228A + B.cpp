/* HDU1228 A + B */
 
#include <iostream>
#include <map>
#include <string>
 
using namespace std;
 
const int PLUS = 100;
const int EQUAL = 200;
 
int main()
{
    int a, b;
    string s;
    map<string, int> m;
 
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    m["+"] = PLUS;
    m["="] = EQUAL;
 
    for(;;) {
        a = 0;
        while(cin >> s) {
            if(m[s] == PLUS)
                break;
            a = a * 10 + m[s];
        }
 
        b = 0;
        while(cin >> s) {
            if(m[s] == EQUAL)
                break;
            b = b * 10 + m[s];
        }
 
        if(a == 0 && b == 0)
            break;
        else
            cout << a + b << endl;
 
    }
 
    return 0;
}

