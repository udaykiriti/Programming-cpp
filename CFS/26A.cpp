#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 2; i <= n; i++)
        if (cnt[i] == 0)
            for (int j = i; j <= n; j += i)
                cnt[j]++;

    int result = 0;
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 2)
            result++;

    cout << result << endl;
    return 0;
}