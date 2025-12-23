#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
	int t,n; cin>>t;
	while(t--)
	{
		int n; cin>>n;
        bool flag=true;
        for(int i=2;i<=floor(sqrt(n)+0.5);i++)
          if(n%i==0)
          {
            int a=n/i,b=n-a;
            cout<<a<<" "<<b<<endl;
            flag=false;
            break;
          }
        if(flag)
          cout<<1<<" "<<n-1<<endl;
	}
	return 0;
}
