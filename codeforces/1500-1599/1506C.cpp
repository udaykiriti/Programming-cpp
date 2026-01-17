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
   created: 08 18:31:53    
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
 
 void solve(){
    //soLuSHoNN hErE.........
    string a,b;
    cin >> a >> b;
    int m = a.size();
    int n = b.size();
    int res = m + n;
    for(int i = 0 ; i < m ; i++){
        for(int j = 1 ; j <= m-i ; j++){
            string sa = a.substr(i , j);
            if(b.find(sa) != string::npos){
                int ops = (m-j) + (n-j);
                res = min(res , ops);
            }
        }
    }
    cout << res << endl;
 }
 
 int main(){
     //freopen("in.txt","r",stdin);
     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
     int t(1), tcase(0); cin>>t;
     while (++tcase, t--) solve();
 }


/* 

string LCS(string X, string Y, int m, int n) {
    int maxlen = 0, endingIndex = m;
    int lookup[m + 1][n + 1];
    memset(lookup, 0, sizeof(lookup));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
                if (lookup[i][j] > maxlen) {
                    maxlen = lookup[i][j];
                    endingIndex = i;
                }
            }
        }
    }
    return X.substr(endingIndex - maxlen, maxlen);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string X, Y;
        cin >> X >> Y;
        int m = X.size(), n = Y.size();
        string ans = LCS(X, Y, m, n);
        int ok = ans.size();
        int c = (m - ok) + (n - ok);
        cout << c << "\n";
    }
    return 0;
}

  */