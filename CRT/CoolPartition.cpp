#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int>r(n+1,0);
        for(int x:a) r[x]++;
        vector<char> inN(n+1,0), inR(n+1,0);
        vector<int> N, R;
        int bad=0, req=0, seg=0;
        for(int i=0;i<n;i++){
            int x=a[i];
            if(inR[x]){
                inR[x]=0;
                req--;
            }
            r[x]--;
            if(inN[x]){
                if(r[x]==0) bad++;
            } else {
                inN[x]=1;
                N.push_back(x);
                if(r[x]==0) bad++;
            }
            if(req==0 && bad==0){
                seg++;
                for(int y:N){
                    inR[y]=1;
                }
                req = N.size();
                for(int y:N){
                    inN[y]=0;
                }
                N.clear();
                bad=0;
            }
        }
        seg++;
        cout<<seg<<"\n";
    }
    return 0;
}
//c