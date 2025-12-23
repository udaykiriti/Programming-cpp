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
   created: 08 19:17:24    
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
 
 int agn[101];


void solve(){
    //soLuSHoNN hErE.........
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) agn[i] = 0;

    for(int i = 0; i < n; ++i){
        int z; cin >> z;
        for(int j = 0; j < z; ++j){
            int v; cin >> v;
            if (v >= 1 && v <= m) agn[v] = 1;
        }
    }
    for(int i = 1; i <= m; ++i){
        if(!agn[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

 
 int main(){
     //freopen("in.txt","r",stdin);
     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
     int t(1), tcase(0); //cin>>t;
     while (++tcase, t--) solve();
 }
