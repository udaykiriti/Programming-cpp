#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
  int a, b; cin>>a>>b;
  int hip, sip;
  hip = a <= b ? a : b;
  sip = ((a <= b ? b : a) - hip)/2;
  cout<<hip<<" "<<sip;
}
