#include <bits/stdc++.h>
using namespace std;

int solve(int n,int k){
  int pos = 1 << k;
  return n | pos;
}

int main(){
  int n,k;
  cin >> n >>k;
  cout << solve(n,k);
}
