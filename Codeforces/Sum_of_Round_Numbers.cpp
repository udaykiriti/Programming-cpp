#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin>>t;
  int n;
  while(t--){
    cin>>n;
    int count = 0;
    int arr[n], i = 0;
    while(n){
      arr[i] = n%10;
      n /= 10;
      count += arr[i] == 0 ? 0 : 1;
      i++;
    }
    cout<<count<<endl;
    FOR(j,0,i){
      if(arr[j] != 0){
        cout<<arr[j] * pow(10, j)<<" ";
      }
    }
    cout<<endl;
  }
}
