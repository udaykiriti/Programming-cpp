#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define debug(n) cout<<(n)<<endl;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  stack<char> st; string s; cin>>s;
  FOR(i,0,s.size())
    if(!st.empty() && st.top() == s[i])
      st.pop();
    else
      st.push(s[i]);
  if(st.empty())
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}