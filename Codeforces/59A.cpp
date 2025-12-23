#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define TO_LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define TO_UPPER(s) transform(s.begin(), s.end(), s.begin(), ::toupper)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string s; cin>>s;
  int low = 0, up = 0;
  FOR(i, 0, s.size())
  {
    if (s[i] >= 'a')
      low++;
    else
      up++;
  }

  if (low >= up)
    TO_LOWER(s);
  else
    TO_UPPER(s);
  cout<<s<<endl;
}