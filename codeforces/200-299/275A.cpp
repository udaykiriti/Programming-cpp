#include <bits/stdc++.h>
using namespace std;

int main() {
    int tab[3][3];
    bool result[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result[i][j] = true;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> tab[i][j];

    int dx[] = {0, -1, 1, 0, 0};
    int dy[] = {0, 0, 0, -1, 1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab[i][j] % 2 != 0) {
                for (int d = 0; d < 5; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
                        result[ni][nj] = !result[ni][nj];
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << (result[i][j] ? 1 : 0);
        }
        cout << '\n';
    }

    return 0;
}