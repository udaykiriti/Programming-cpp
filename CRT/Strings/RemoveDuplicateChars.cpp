#include <iostream>
using namespace std;

int main()
{
  string str;
  getline(cin, str);
  bool seen[256] = {false};
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (!seen[(int)str[i]])
    {
      cout << str[i];
      seen[(int)str[i]] = true;
    }
  }
  cout << endl;
  return 0;
}
