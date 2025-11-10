#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int t1=0,t2=1;
  cin>>n;
  int next;
  for (int i = 1; i <= n; i++)
  {
    cout<<t1<<" ";
    next=t1+t2;
    t1=t2;
    t2=next;
  }
  cout<<endl;
  return 0;  
}