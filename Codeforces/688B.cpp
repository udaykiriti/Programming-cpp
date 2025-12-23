#include <bits/stdc++.h>
using namespace std;
#define reverse(x) reverse(x.begin(), x.end())

int main()
{
  string s; cin>>s;
  string s2 = s;
  reverse(s2);
  string s3 = s + s2;
  cout<<s3<<endl;
  return 0;
}