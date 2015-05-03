// string::rbegin/rend
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  std::string str ("now step live...");
  string s2 ("abcd");
  string::reverse_iterator it2 = s2.rbegin();
  for (std::string::reverse_iterator rit=str.rbegin(); rit!=str.rend()&&it2!=s2.rend(); ++rit, it2++)
  {
    std::cout << *rit;
    cout<<*it2;
    }
  return 0;
}
