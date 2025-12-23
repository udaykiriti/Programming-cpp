#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; i++)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n; cin >> n;
    cin.ignore();
    string str;
    getline(cin,str);
    unordered_map<char,int> m;
    for(auto it : str)
    {
        m[it]++;
    }
    vector<int> ans;
    while(m['o'] && m['n'] && m['e'])
    {
        m['o']--,m['n']--,m['e']--;
        ans.push_back(1);
    }
    while(m['z'] && m['e'] && m['r'] && m['o'])
    {
        m['z']--,m['e']--,m['r']--,m['o']--;
        ans.push_back(0);
    }
    int sz = ans.size()-1;
    FOR(i,0,sz)
    {
        cout << (i==0?"":" ") << ans[i];
    }
    return 0;
}
