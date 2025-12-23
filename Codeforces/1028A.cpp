#include <bits/stdc++.h>
using namespace std;

void startPos(int &a, int &b, int n, int m, vector<vector<char>> &arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'B') {
                a = i;
                b = j;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];

    int a, b;
    startPos(a, b, n, m, arr);
    int i = a;
    while (i < n && arr[i][b] == 'B') i++;
    int a1 = i; int j = b;
    while (j < m && arr[a][j] == 'B') j++;
    int b1 = j;
    cout << (a + a1) / 2 + 1 << " " << (b + b1) / 2 + 1 << "\n";
    return 0;
}