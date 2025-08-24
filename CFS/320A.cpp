#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll i, j, k; string s; cin>>s;
  bool flag = true;
  for (i = 0; i < s.length();){
    if (s[i] == '1' && s[i + 1] == '4' && s[i + 2] == '4'){
      i += 3;
    }
    else if (s[i] == '1' && s[i + 1] == '4'){
      i += 2;
    }
    else if (s[i] == '1'){
      i++;
    }
    else{
      flag = false;
      break;
    }
  }
  if (flag) cout << "YES";
  else cout << "NO";
  return 0;
}