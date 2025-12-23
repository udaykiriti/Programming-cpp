#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, count = 1; cin >> n;
  int arr[n];
  FOR (i , 0 , n)
    cin >> arr[i];
  FOR ( i , 0, n - 1)
    if (arr[i] != arr[i + 1])
      count++;
  cout << count;
}