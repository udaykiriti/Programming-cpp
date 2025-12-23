#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
  int t; cin>>t;
  int n, steps;
  string s;
  while(t--){
    cin>>n>>s;
    steps = 0;
    for(int i = 0; i < n-1; i++)
      if(s[i] != '0')
        steps += (s[i] - '0') + 1;
    steps += (s[n-1] - '0');
    cout<<steps<<endl;
  }
  return 0;
}