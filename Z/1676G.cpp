#include <bits/stdc++.h>
using namespace std;

void dfs(int u, string &s, vector<int> &ans, vector<vector<int>> a)
{
    if(a[u].size()==0)
    {
        ans[u]=(s[u-1]=='W'?1:-1);
        return;
    }
    int sum=0;
    for(int i=0;i<a[u].size();i++)
    {
        dfs(a[u][i],s,ans,a);
        sum+=ans[a[u][i]];
    }
    ans[u]=sum+(s[u-1]=='W'?1:-1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<vector<int>> a(n+1);
        for(int i=2;i<=n;i++)
        {
            int k;
            cin >> k;
            a[k].push_back(i);
        }
        string s;
        cin >> s;
        vector<int> ans(n+1, -1);
        dfs(1,s,ans,a);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==0)
                cnt++;
        }
        cout << cnt << "\n";
    }

}