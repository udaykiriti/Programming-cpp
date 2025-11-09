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
   created: 08 18:47:06    
 */
 
 
 // g++ -std=c++17 new.cpp -o new
 // ./new
 //g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name 
 //./file-name
 #undef _GLIBCXX_DEBUG
 #include <bits/stdc++.h>
 using namespace std;
 #define ll long long
 #ifdef LOCAL
 #include "algo/debug.h"
 #else
 #define debug(...) 42
 #endif
 
 void solve(){
    //soLuSHoNN hErE.........
    ll a,b,res(0);
    cin >> a >> b;
    for(ll i = 0 ;i <= 63 ; i++){
        for(ll j = 0; j <= i-2 ; j++){
            ll x = pow(2 ,i) - pow(2,j)-1;
            if(x >= a && x <= b) res++;
        }
    }
    cout << res << '\n';
 }
 
 int main(){
     //freopen("in.txt","r",stdin);
     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
     int t(1), tcase(0); //cin>>t;
     while (++tcase, t--) solve();
}
