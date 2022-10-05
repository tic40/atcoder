#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
  int n; cin >> n;
  n *= 2;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

	// dp[l][r] := l,l+1..., r番目の人だけが抜けるのに必要な最小のコスト
	vector dp(n,vector<int>(n,INF));
	REP(i,n-1) dp[i][i+1] = abs(a[i]-a[i+1]);

	for (int i = 3; i < n; i += 2) {
    REP(j,n-i) {
			int cl = j, cr = j + i;
			for (int k = cl; k <= cr-1; k++) {
				chmin(dp[cl][cr], dp[cl][k] + dp[k+1][cr]);
			}
			chmin(dp[cl][cr], dp[cl+1][cr-1] + abs(a[cl] - a[cr]));
		}
	}

	cout << dp[0][n-1] << endl;
	return 0;
}