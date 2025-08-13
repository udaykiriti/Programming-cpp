#include <iostream>
using namespace std;

int main()
{
  string str;
  getline(cin, str);
  int len = 0;
  while (str[len] != '\0')
    len++;
  for (int i = 0; i < len; i++)
  {
    for (int j = i; j < len; j++)
    {
      for (int k = i; k <= j; k++)
      {
        cout << str[k];
      }
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}
