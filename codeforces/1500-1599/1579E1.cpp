#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  int n;
  while(t--){
    deque <int> deqs;
    cin>>n; int x;
    for(int i = 0; i < n;i++){
      cin>>x;
      if(x > deqs.front()){
        deqs.push_back(x);
        continue;
      }
      deqs.push_front(x);
    }
    for(int i = 0; i < n; i++) cout<<deqs.at(i)<<" ";
    cout<<endl;
  }
}