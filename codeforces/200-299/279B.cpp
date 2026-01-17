#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl;


void solve()
{
  int n, t; cin >> n >> t;
  vector<int> books(n);
  for (int i = 0; i < n; ++i)
    cin >> books[i];

  int left = 0, current_time = 0, max_books = 0;
  for (int right = 0; right < n; ++right)
  {
    current_time += books[right];
    while (current_time > t)
    {
      current_time -= books[left];
      left++;
    }
    max_books = max(max_books, right - left + 1);
  }
  cout << max_books << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  solve();
  return 0;
}