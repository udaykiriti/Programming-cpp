
/*
 *                                                     ----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          --~ ~~
 *                    -.            \_|//     |||\  ~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \            _/-
 *         ---~~~.==~||\=_    -_--~/_-~|-   |\   \        _/~
 *     _-~~     .=~    |  \-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       --
 *                       |--_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-____--~-/                  ==.
 *                       ((->/~   '.|||' -_|    -/ ,              . _||
 *                                  -_     ~\      ---l__i__i__i--_/
 *                                  _-~-__   ~)  \--______________--
 *                                //.-~~~-~_--~- |-------~~~~~~
 *                                       //.-~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                       DiVine BeAst bleSSes, may there be no buGs
 */

/*
  author:  -----          
  created: 17 22:15:51    
*/



// g++ -std=c++17 new.cpp -o new
// ./new
//g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name 
//./file-name
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define ll long long

void solve(){
   //soLuSHoNN hErE.........
   int n;
   cin >> n;
   string s;
   cin >> s;
   map<int , vector<int>> mp;
   for(int i =0 ;i < n ;i++){
    mp[s[i]].push_back(i);
   }
   ll ans = 0;
   for (int i = n - 1; i >= 1; i--) {
        ans += 1;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (ch == s[i - 1]) {
                continue;
            }
            auto &vec = mp[ch];
            if (vec.empty()) {
                continue;
            }
            if (vec[0] < i) {
                ans += 1;
            }
        }
    }
    ans += 1;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        auto &vec = mp[ch];
        if (!vec.empty()) {
            ans += 1;
        }
    }
    ans -= 1;
    cout << ans << '\n';
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}