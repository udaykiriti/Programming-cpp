#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int n, m; cin >> n >> m;
  unordered_map<string, pair<string, string>> dictionary;
  for (int i = 0; i < m; ++i)
  {
    string a, b; cin >> a >> b;
    dictionary[a] = {a, b};
  }
  vector<string> lecture(n);
  for (int i = 0; i < n; ++i) cin >> lecture[i];
  for (const string &word : lecture)
  {
    string word1 = dictionary[word].first;
    string word2 = dictionary[word].second;
    if (word1.length() <= word2.length()) cout << word1 << " ";
    else cout << word2 << " ";
  }
  cout << endl;
  return 0;
}