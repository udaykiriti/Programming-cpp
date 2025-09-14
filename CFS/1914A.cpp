#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
  int n; cin >> n;
  string log; cin >> log;
  map<char, int> time_spent;
  for (char ch : log) time_spent[ch]++;
  int solved = 0;
  for (auto [ch, time] : time_spent){
    int required = ch - 'A' + 1;
    if (time >= required)
      solved++;
  }
  cout << solved << endl;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
