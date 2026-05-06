/* Maximum contiguous subarray Sum of array optimized  approach */

#include <bits/stdc++.h>
using namespace std;
/* arr[3]={-1,3,-2}; */
/*
 * subarrays are
    -1
    -1 3
    -1 3 -2
    3
    3 -2
    -2
    3
 * ans = 3;
*/

//most optimized version kadane's algo with one for loop
int solve() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum , maxi;
    sum = 0,maxi = arr[0];
    for(int i = 0;i < n; i++) {
        sum += arr[i];
        maxi = max(sum , maxi);
        if(sum < 0)
            sum=0;
    }
    cout << maxi << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
