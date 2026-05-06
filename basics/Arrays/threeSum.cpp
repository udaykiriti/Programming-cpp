#include <bits/stdc++.h>
using namespace std;

// Find all unique triplets with sum 0
// Time: O(n^2)

void threeSum(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) {
            continue;
        }

        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            int sum = a[i] + a[l] + a[r];

            if (sum == 0) {
                cout << a[i] << " " << a[l] << " " << a[r] << "\n";
                found = true;
                l++;
                r--;

                while (l < r && a[l] == a[l - 1]) {
                    l++;
                }
                while (l < r && a[r] == a[r + 1]) {
                    r--;
                }
            } else if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
    }

    if (!found) {
        cout << -1 << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    threeSum(nums);
    return 0;
}
