/******************************
 *    author:  uday           *
 *    created: 27 00:11:05    *
 ******************************/

// g++ -std=c++17 new.cpp -o new
// ./new
//g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name 
//./file-name
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define vi vector<int>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
   //solution here.........
   string source , desti;
   getline(cin,source);
   getline(cin,desti);
   ifstream src(source , ios::binary);

   if(!src){
    cerr << "oops, chk the src file ...." << endl;
    return ;
   }
   ofstream dest(desti,ios::binary);
    if(!dest){
    cerr << "oops, chk the dst file ...." << endl;
    return ;
   }
   char buff[1024];
   while(src.read(buff,sizeof(buff))){
    dest.write(buff,src.gcount());
   }
   dest.write(buff,src.gcount());
   cout<<"DOne!!..."<<endl;
   src.close();
   dest.close();
   return ;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}