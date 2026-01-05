#include <iostream>
#include "include/number_theory_basics.hpp"

using namespace std;
using namespace NumberTheory;

int main(){
    ll n;
    cin >> n;
    ll t1=0,t2=1, next;
    for (ll i = 1; i <= n; i++) {
        cout << t1 << " ";
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
    cout << endl;
    return 0;  
}
