/*
 * majority element of an array
 * element with frequency > (n/2) {n: size of array}
 * time complexity : O(n) || space complexity : O(1)
 */
#include <bits/stdc++.h>
using namespace std;
/*
arr = [2 2 1 1 2 2]
    ans=0, cnt=1

    2=2  -> cnt=2
    2=2  -> cnt=3
    1!=2 -> cnt=2
    1!=2 -> cnt=1
    2==2 -> cnt=2
    2==2 -> cnt=3
    final = 2
*/
void solve(){
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans{0};
    int cnt = 1; // set fst ele as 1;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[ans]) cnt++;
        else cnt--;
        if(cnt == 0){
            ans = i;// i the element
            cnt = 1;
        }
    }
    cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == arr[ans]) cnt++;
    }
    if(cnt > n/2)
        cout << arr[ans] << '\n';
    else
        cout << -1 << '\n';
    cout << ans << '\n';
}

int main(){
    int t{1};
    while(t--){
        solve();
    }
    return 1;
}
