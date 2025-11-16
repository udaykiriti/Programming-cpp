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
g++ -std=c++17 new.cpp -o new
./new
g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name 
./file-name 
*/
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n , p;
int ans[1005] , id[1005];
bool f[1005];
mt19937 rnd(time(0));

int query(int l,int r) {

	for(int i = 1 ; i <= n ; i++){
		f[i] = 0;
    }

	for(int i = l ; i <= r ; i++){
		f[id[i]] = 1;
    }

	for(int i = 1 ; i <= n ; i++){
		cout << (f[i] ? 'T' : 'F');
    }

	cout << "\n";
	cout.flush();

	int x; 
	cin >> x;

	if(x == -1){
		exit(1);
	}

	if(l==1 && r==n){
		p = x;
	}

	x = n - x;

	if(!x){
		exit(0);
	}

	return ((r - l + 1) + p - x) >> 1;
}
void solve(int l,int r,int num) {
	//soLuSHoNN hErE.........
	if(num == r - l + 1) {
		for(int i = l ; i <= r ; i++)
			ans[id[i]] = 1;
		return;
	}
	if(!num) {
		return;
	}

	int mid = l + r >> 1;
	int x = query(l , mid);
	solve(l , mid , x);

	solve(mid+1 , r , num-x);
}

int main(){
	/*
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout); 
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	/*
	int t(1), tcase(0); cin>>t;
	while (++tcase, t--) solve();
	*/
	cin >> n;

	for(int i = 1 ; i <= n ; i++){
		id[i] = i;
	}

	for(int i = 1 ; i <= n ; i++){
		swap(id[i] , id[rnd() % i+1]);
	}

	solve(1 , n , query(1 , n));

	for(int i = 1 ; i <= n ; i++){
		cout << (ans[i] ? 'T' : 'F');
	}

	cout << "\n";
	cout.flush();
	return 0;
}