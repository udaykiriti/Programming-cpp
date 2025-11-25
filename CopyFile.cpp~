/*
  author:  -----          
  created: 14 15:01:51    
*/

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

bool cmp(){
	return x > y;
}

bool solve(){
   //solution herE.........
   string source , desti;
   getline(cin , source); // src path as input
   getline(cin , desti); // dest path as input
   ifstream src(source , ios::binary);

  	if(!src){
    	cerr << "oops, check the source file ...." << endl;
    	return 0;
   }
   ofstream dest(desti , ios::binary);
   if(!dest){
      cerr << "oops, check the destination file ...." << endl;
      return 0;
      dest.write(buff , src.gcount());
   }
   dest.write(buff , src.gcount());
   cout << "Done!!..." << endl;
   src.close();
   dest.close();
   return 1;
}

int main(){
	/*	
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cout.tie(0) -> ios::sync_with_stdio(0);
    int t(1), tcase(0); //cin>>t;
    
    while (++tcase, t--){ 
    	bool ok = solve();
    }
    cout << (ok ? "Completed" : "Something went wrong,debug or run again");
    return 0;
}