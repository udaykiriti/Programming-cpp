/// Quandales for Nyomber of PalindroMOes.
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str; 
    cin>> str;
    int q, n = str.size(); 
    cin>> q;
    // bool a[n+1][n+1];
    // int_fast32_t b[n+1][n+1];
    int c[n+1][n+1];
    // int_fast64_t pfx[n];
    // memset(a, 0, sizeof a);
    // memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    // memset(pfx, 0, sizeof pfx);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int nutty = 1;
            for(int k = i; k <= j; k++){
                if(str[k] != str[i+j-k]){
                    nutty = 0;
                    break;
                }
            }
            // a[i+1][j+1] = nutty;
            c[i+1][j+1] = nutty;
            //pfx[j] += nutty;
        }
    }
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            if(j){
//                a[i][j]+=a[i][j-1];
//            }
//            else if(i){
//                a[i][j] = a[i-1][n-1];
//            }
//        }
//    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            c[i][j]+=c[i-1][j];
            c[i][j]+=c[i][j-1];
            c[i][j]-=c[i-1][j-1];
        }
    }
/*    for(int i = 1; i <= n; i++){
       for(int j = 1; j <= n; j++){
           cout<< a[i][j] << " ";
       }
       cout<< "\n";
   } cout<< "\n\nc[]:\n";
   for(int i = 0; i <= n; i++){
       for(int j = 0; j <= n; j++){
           cout<< c[i][j] << " ";
       }
       cout<< "\n";
   }
   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           pfx[i]+=a[j][i];
       }
       cout<< pfx[i] << " ";
   }
   cout<< "\n";
   for(int i = 0; i < n; i++){
       if(i) pfx[i]+=pfx[i-1];
       cout<< pfx[i] << " ";
   }
   cout<< "\n\n";
   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           for(int p = i; p <= j; p++){
               for(int q = i; q <= j; q++){
                   b[i][j]+=a[p][q];
               }
           }
           // cout<< b[i][j] << " ";
       }
       // cout<< "\n";
   }
 */
    while(q--){
        ll uandale_dingle = 0;
        int l, r; cin>> l >> r;
        //cout<< format("a[{}][{}]: {} ;\n",i,j,a[i][j]);
        uandale_dingle = c[r][r] - c[l-1][r] - c[r][l-1] + c[l-1][l-1];
        /// query = bottom right corner - top right corner -
        /// bottom left corner + top left corner.
        cout<< uandale_dingle << "\n";
    }
    return 0;
}
