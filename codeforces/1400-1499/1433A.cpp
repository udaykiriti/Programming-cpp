#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(0);
  int t; cin>>t;
  string n;
  int count = 0;
  while(t--){
    cin>>n;
    count = 0;
    count += (stoi(n)%10 - 1) * 10;
    if(n.size() == 1){
      count += 1;
      cout<<count<<endl;
      continue;
    }
    if(n.size() == 2){
      count += 3;
      cout<<count<<endl;
      continue;
    }
    if(n.size() == 3){
      count += 6;
      cout<<count<<endl;
      continue;
    }
    if(n.size() == 4){
      count += 10;
      cout<<count<<endl;
      continue;
    }
  }
  return 0;
}