/*  Dutch Flag Algo: To separate three different entities
    e.g :- Sort 0s,1s and 2s in an array without using sorting algo
    Complexity : O(n)
*/

#include <iostream>
using namespace std;

/*  0 0 0 1 1 1 ? ? ? ? 2 2 2
          |     |     |
          v     v     v
         Low   Mid   High

   > In this algo, we tend to shrink this '?' region
   whose ends are pointed by Mid and High indexes.

   > Low points to the region where the 1s start

*/


void solve(){
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    //mid to high is the region we are about to shrink
    int low = 0, mid = 0;
    int high = (int)arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high--]);
        }
    }

    for (int x : arr) {
        cout << x << " ";
    }
}


int main(){
    solve();
    return 0;
}
