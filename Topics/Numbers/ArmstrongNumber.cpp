#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,digits=0,sum=0,org;
  cin>>n;
  org=n;
  int temp=n;
  while (temp!=0)
  {
    temp/=10;
    digits++;
  }
  temp=n;
  while (temp!=0)
  {
    int digit=temp%10;
    sum+=pow(digit,digits);
    temp/=10;
  }
  if(sum==org) cout<<"YES";
  else cout<<"NO";

}