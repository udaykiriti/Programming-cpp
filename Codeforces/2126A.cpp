#include<bits/stdc++.h>
using namespace std;

int main(int argc , char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        string x; cin >> x;
        set<char> digits_in_x(x.begin(), x.end());
        for (int y = 0; y <= 9; ++y) {
            char digit = '0' + y;
            if (digits_in_x.count(digit)) {
                cout << y << '\n';
                break;
            }
        }
    }
}