#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9;

// dp[l][r] = (l,l+1..., r番目の人だけが抜けるのに必要なコスト)
int dp[405][405];

int main() {
  int n; cin >> n;
  n *= 2;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // 初期化
  REP(i,n) {
    REP(j,n) dp[i][j] = INF;
		if (i+1 < n) dp[i][i + 1] = abs(a[i]-a[i + 1]);
	}

  // dp
	for (int i = 3; i < n; i += 2) {
    REP(j,n-i) {
			int cl = j, cr = j + i;
			for (int k = cl; k <= cr - 1; k++) dp[cl][cr] = min(dp[cl][cr], dp[cl][k] + dp[k + 1][cr]);
			dp[cl][cr] = min(dp[cl][cr], dp[cl + 1][cr - 1] + abs(a[cl] - a[cr]));
		}
	}

	cout << dp[0][n-1] << endl;
	return 0;
}