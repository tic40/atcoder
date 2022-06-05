#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const ll LINF = 1e18+5;

vector<vector<ll>> dp(401, vector<ll>(401, LINF));
vector<ll> m(401);
vector<int> a(401);

// O(n^3)
// dp[l][r]=(区間[l,r]に相当するスライムが1匹にまとまっているとき、それを分解するために必要な最小コスト)
ll f(int l, int r) {
  if (dp[l][r] != LINF) return dp[l][r];
	if (l == r) return 0;

	//どこで切るか全通り試す
	ll fans = LINF;
  for(int i = l; i < r; i++) fans = min(fans, f(l,i) + f(i+1, r));
	return dp[l][r] = fans + (m[r+1] - m[l]);
}

int main() {
  int n; cin >> n;
  REP(i,n) cin >> a[i];
  REP(i,n) m[i+1] = m[i] + a[i]; // 累積和

  cout << f(0,n-1) << endl;
  return 0;
}
