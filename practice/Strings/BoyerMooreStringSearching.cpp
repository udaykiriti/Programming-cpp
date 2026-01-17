/*
g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL BoyerMooreStringSearching.cpp  -o BoyerMooreStringSearching 
./BoyerMooreStringSearching <in.txt> out.txt
*/
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
//#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int ToT = 256;

void badcharHeuristic(string str,int size,int badchar[ToT]){
    memset(badchar , -1 , sizeof(int)*ToT);
    for(int i = 0; i< size ;i++){
        badchar[(int)str[i]] = i;
    }
}

void search(string txt , string pat){
    int m(pat.size());
    int n(txt.size());
    if(m == 0 || m > n){
        cout << "strings cant be compares";
        return;
    }

    int badchar[ToT];
    badcharHeuristic(pat,m,badchar);

    int s(0);
    while(s <= (n-m)){
        int j = m-1;
        while(j >= 0 and pat[j] == txt[s+j]) j--;
        if (j < 0) {
            cout << "pattern occurs at shift = " << s << '\n';

            s += (s + m < n) ? m - badchar[(unsigned char)txt[s + m]] : 1;
        } else {
            s += max(1, j - badchar[(unsigned char)txt[s + j]]);
        }
    }

}

void solve(){
  //soLuSHoNN hErE.........
  string txt = "ABAAABCD",pat ="ABC";
  search(txt,pat);
}

int main(){
     /*
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
     */
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
    return 0;
}