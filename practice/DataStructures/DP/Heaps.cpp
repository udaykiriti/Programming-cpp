#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void printelements(vector<int> &vec){
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

int main(int argc , char *argv[]){
    //int n; cin>>n;
    vector<int>vec ={20, 30, 40, 25, 15};
    // cout<<"vector"<<endl;
    // printelements(vec);
    make_heap(vec.begin(),vec.end());
    //cout<<"In heap"<<endl;
    printelements(vec);
    cout << "max ele: " << " " << vec.front() << endl ;
    vec.push_back(50);
    push_heap(vec.begin(),vec.end());
    printelements(vec);
    pop_heap(vec.begin(),vec.end());
    vec.pop_back();
    printelements(vec);
    // if(is_heap(vec.begin(),vec.end())) cout<<"yes"<<endl;
    // else cout<<"no"<<endl;
    // return 0;
    cout<<"================="<<endl;
    sort_heap(vec.begin(),vec.end());
    printelements(vec);
    cout << "max ele: " << " " << vec.front() << endl ;

    if(is_heap(vec.begin(),vec.end())) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}