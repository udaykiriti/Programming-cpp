#include <iostream>
using namespace std;

bool isVowel(char c)
{
  if (c >= 'A' && c <= 'Z')
    c += 32;
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isAlpha(char c)
{
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main()
{
  string str;
  getline(cin, str);
  int vowels = 0, consonants = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (isAlpha(str[i]))
    {
      if (isVowel(str[i]))
        vowels++;
      else
        consonants++;
    }
  }
  cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;
  return 0;
}
