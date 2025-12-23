#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,a;
    set<int>s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        s.insert(a);
    }
    if(s.size() < 2){
        cout<<"NO"<<endl;
    }
    else{
        set<int> :: iterator it;
        int c = 0;
        for(it=s.begin(); it!=s.end(); it++){
            if(c == 1){
                cout<<*it<<endl;
                break;
            }
            c++;
        }
    }
    return 0;
}