#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  const int MAX = 1000;
  char d, c[MAX];
  int i = 0;
  while(d != '}'){
    cin>>d;
    if(d >= 97 && d <= 122){
      c[i] = d;
      i++;
    }
  }
  c[i] = '\0';
  sort(c, c+i);
  char h = 'A';
  int count = 0;
  for(int j = 0; j < i; j++){
    if(c[j] != h){
      count++;
      h = c[j];
    }
  }
  cout<<count;
}