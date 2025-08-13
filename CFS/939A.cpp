#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAX = 1000005;

int main() {
    // Uncomment below lines if you want to read/write from files
    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    int n, i, arr[5001], a, b, c;
    while (scanf("%d", &n) != EOF) {
        set<int> mySet;
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            mySet.insert(arr[i]);
        }
        if (mySet.size() < 3) {
            printf("NO\n");
        } else {
            mySet.clear();
            bool found = false;
            for (i = 0; i < n; i++) {
                a = arr[i];
                b = arr[a - 1];
                c = arr[b - 1];

                if ((a != b) && (b != c) && (c != a) && arr[c - 1] == a) {
                    found = true;
                    printf("YES\n");
                    break;
                }
            }
            if (!found) 
                printf("NO\n");
        }
    }
    return 0;
}