/*
 Description : Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
 We can break items for maximizing the total value of knapsack
 Algorithm Type: Greedy
 Time Complexity: O(n*log(n))
 */

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int val,wt;
};
/*
W = 50

(val, wt):
(60,10) (100,20) (120,30)

ratio:
6 5 4

sorted:
(60,10) (100,20) (120,30)

cur=0, val=0

+ (60,10) -> cur=10, val=60
+ (100,20)-> cur=30, val=160
+ (120,30)-> only 20 taken

rem = 20
cur = (120/30)*20 = 80

finalVal = 160 + 80 = 240
*/
double fractionalKnapsack(int w, vector<Item> &vec, int n){
    sort(vec.begin(),vec.end(), [](Item a, Item b){
       return(double)a.val / a.wt > (double)b.val/b.wt;
    });
    int cur{0};
    double finalVal{0.0};

    for(int i = 0; i < n; i++){
        if(cur + vec[i].wt <= w){
            cur += vec[i].wt;
            finalVal += vec[i].val;
        }else{
            int rem = w - cur;
            finalVal += (vec[i].val / (double)vec[i].wt) * (double)rem;
            break;
        }
    }
    return finalVal;
}

int main(){
    int w; // weight
    cin >> w;
    int n;
    cin >> n; // #t0T {val-wt} pairs
    vector<Item> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i].val;
        cin >> vec[i].wt;
    }
    cout << fractionalKnapsack(w,vec,n);
}
