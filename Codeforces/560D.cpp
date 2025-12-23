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
   created: 08 18:58:34    
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

string a,b;

string smallest(string s) {
    if (s.length() % 2 == 1) return s;
    string s1 = smallest(s.substr(0, s.length()/2));
    string s2 = smallest(s.substr(s.length()/2, s.length()/2));
    if (s1 < s2) return s1 + s2;
    else return s2 + s1;
}
 
 void solve(){
    //soLuSHoNN hErE.........
    cin >> a >> b;
	if (smallest(a) == smallest(b)) cout << "YES" << endl;
    else cout << "NO" << endl;
 }
 
 int main(){
     //freopen("in.txt","r",stdin);
     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
     int t(1), tcase(0); //cin>>t;
     while (++tcase, t--) solve();
 }
