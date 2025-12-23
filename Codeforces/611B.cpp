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
 #define ll long long
 ll a,b,num = 0;
 
void dfs(ll x, int y){
    if(x > b) return;
    else if(x >= a and y == 1) num++;
    if(y == 0) dfs(x<<1 , 1);
    dfs((x<<1)+1,y);
}

 void solve(){
    //soLuSHoNN hErE.........
    cin >> a >> b;
    dfs(1,0);
    cout << num << '\n';
 }
 
 int main(){
     //freopen("in.txt","r",stdin);
     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
     int t(1), tcase(0); //cin>>t;
     while (++tcase, t--) solve();
}
