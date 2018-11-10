#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	vector<int>a, b, dp[2];
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for(int i=0;i<a.size();i++){
		cin>>a[i];
	}
	for(int i=0;i<b.size();i++){
		cin>>b[i];
	}
	dp[0].resize(m+1);
	dp[1].resize(m+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1])dp[i&1][j]=dp[(i&1)^1][j-1]+1;
			else dp[i&1][j]=max(dp[i&1][j-1],dp[(i&1)^1][j]);
		}
	}
	cout<<dp[n&1][m]<<'\n';
}