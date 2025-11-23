/*
              __                  __
             ( _)                ( _)
            / / \              / /\_\_
           / /   \            / / | \ \
          / /     \          / /  |\ \ \
         /  /   ,  \ ,       / /   /|  \ \
        /  /    |\_ /|      / /   / \   \_\
       /  /  |\/ _ '_|\    / /   /   \    \
      |  /   |/  0 \0\ \  / |    |    \    \
      |    |\|      \_\_ /  /    |     \    \
      |  | |/    \.\ o\o)  /      \     |    \
      \    |     /\`v-v  /        |    |     \
       | \/    /_| \_|  /         |    | \    \
       | |    /__/_     /   _____  |    |  \    \
       \|    [__]  \_/  |_________  \   |   \    ()
        /    [___] (    \         \  |\ |   |   //
       |    [___]                  |\| \|   /  |/
      /|    [____]                  \  |/\ / / ||
    (  \   [____ /     ) _\      \  \    \| | ||
      \  \  [_____|    / /     __/    \   / / //
      |   \ [_____/   / /        \    |   \/ //
      |   /  '----|   /=\____   _/    |   / //
   __ /  /        |  /   ___/  _/\    \  | ||
  (/-(/-\)       /   \  (/\/\)/  |    /  | /
                (/\/\)           /   /   //
                       _________/   /    /
                      \____________/    
                   buGs geT EaTeNN.
*/

/*
  author:  -----          
  created: 23 13:30:15    
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int long long



void solve() {
    int x, y;
    cin >> x >> y;

    if(x == y){
        cout << "-1" << '\n';
        return;
    }

    if (y > x) swap(x, y);

    int k = (1 << ( __lg(x) + 1 )) - x;

    cout << k<<endl;
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    
    int t(1);
    cin >> t;
    while (t--) solve();
    return 0;
}
