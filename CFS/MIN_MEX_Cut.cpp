#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin>>t;
  string s;
  char elem;
  FOR(i,0,t){
    cin>>s;
    elem = '4';
    int count = 0;
    FOR(j,0,s.size()){
      if(s[j] != elem){
        elem = s[j];
        if(elem == '0'){
          count++;
          if(count == 2){
            break;
          }
          continue;
        }
      }
    }
    cout<<count<<endl;
  }

}
