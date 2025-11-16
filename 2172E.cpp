#include <bits/stdc++.h>
using namespace std;

string permutationOf(int n, long long index) {
    string s = to_string(n);
    sort(s.begin(), s.end());
    vector<string> perms;
    do {
        perms.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    return perms.at((size_t)index - 1);
}

string computeResult(const string &a, const string &b) {
    int A = 0;
    for (size_t i = 0; i < a.size(); ++i) if (a[i] == b[i]) ++A;

    array<int, 10> cntA{}, cntB{};
    for (char c : a) ++cntA[c - '0'];
    for (char c : b) ++cntB[c - '0'];

    int common = 0;
    for (int d = 0; d <= 9; ++d) common += min(cntA[d], cntB[d]);

    int B = common - A;
    return to_string(A) + "A" + to_string(B) + "B";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long j, k;
        cin >> n >> j >> k;

        string pj = permutationOf(n, j);
        string pk = permutationOf(n, k);

        cout << computeResult(pj, pk) << '\n';
    }
    return 0;
}
