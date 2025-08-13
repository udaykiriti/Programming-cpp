#include<bits/stdc++.h>
using namespace std;
#define i64 long long
//using Stacks 
//Finding Next Greater Element
void solve(){
    int n; cin>>n;
    vector<int> vec(n),res(n,-1);
    for(auto &x : vec) cin>>x;
    stack<i64> st;
    //reverse(vec.begin(),vec.end());
    //for(auto x : vec) cout<<x<<" ";
    for(int i = vec.size()-1 ;i >= 0 ;i--){
        while (!st.empty() && st.top()<=vec[i]) st.pop();
        if(!st.empty()) res[i]=st.top();
        st.push(vec[i]);      
    }
    //reverse(res.begin(),res.end());
    for(auto x : res) cout<<x<<" ";
}

int main(int argc , char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t(1); //cin>>t;
    while(t--) solve();
}