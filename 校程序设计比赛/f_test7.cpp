#include <iostream>   
#include <string>     
using namespace std;

int main ()
{
  string pi = "pi is " + std::to_string(3.1415926);
  string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";
  cout << pi << '\n';
  cout << perfect << '\n';
  return 0;
}
