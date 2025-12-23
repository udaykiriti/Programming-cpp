#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int arr[4];
  FOR(i,0,4){
    cin>>arr[i];
  }
  sort(arr, arr+4);
  FOR(i,0,3){
    cout<<(arr[3] - arr[i])<<" ";
  }
}
