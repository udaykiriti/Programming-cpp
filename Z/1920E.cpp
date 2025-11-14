#include <bits/stdc++.h>

using namespace std;

const int N = 2.5e3 + 5;
const int Mod = 998244353;

vector <int> dp[N][N];
int n,lim;
void chadd(int& x,int y)
{
	x = (x + y) % Mod;
	return;
}
void func(void)
{
	scanf("%d%d",&n,&lim);
	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= n;j++)
		{
			dp[i][j].resize(0);
			dp[i][j].resize(n / (j + 1) + 3);
		}
	for(int i = 0;i < lim;i++)
		dp[i + 1][i][0] = 1;
	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= n;j++)
			for(int k = 0;k <= n / (j + 1) + 1;k++)
			{
				if(i + j + 1 <= n && j + k + 2 <= lim)
					chadd(dp[i + j + 1][j][k + 1],dp[i][j][k]);
				if(i + k + 1 <= n)
					chadd(dp[i + k + 1][k][0],dp[i][j][k]);
			}
	int ans = 0;
	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= n / (i + 1) + 1;j++)
			chadd(ans,dp[n][i][j]);
	printf("%d\n",(ans % Mod + Mod) % Mod);
	return;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
		func();
	return 0;
}