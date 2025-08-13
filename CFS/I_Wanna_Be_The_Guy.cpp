#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n, p, q; cin>>n>>p;
  int x;
  set<int, less<int> > s;
  FOR(i,0,p){
    cin>>x;
    s.insert(x);
  }
  cin>>q;
  FOR(i,0,q){
    cin>>x;
    s.insert(x);
  }

  int check = s.size() == n ? 1 : 0;
  if(check == 1)
    cout<<"I become the guy.";
  else
    cout<<"Oh, my keyboard!";
  return 0;
}