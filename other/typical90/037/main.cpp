#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

class RangeMax {
public:
	int size_ = 1;
	vector<long long> dat;

	void init(int sz) {
		while (size_ <= sz) size_ *= 2;
		dat.resize(size_ * 2, -1);
	}
	void update(int pos, long long x) {
		pos += size_;
		dat[pos] = x;
		while (pos >= 2) {
			pos >>= 1;
			dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}
	long long query_(int l, int r, int a, int b, int u) {
		if (l <= a && b <= r) return dat[u];
		if (r <= a || b <= l) return -1;
		long long v1 = query_(l, r, a, (a + b) >> 1, u * 2);
		long long v2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
		return max(v1, v2);
	}
	long long query(int l, int r) {
		return query_(l, r, 0, size_, 1);
	}
};

int n,w;
vector<ll> l,r,v;
RangeMax z[510];
ll dp[510][10010]; // [i][j] := i種類で香辛料の量がjのときの最大の価値

// DP + segment tree(range max)
void solve() {
  REP(i,n+1) REP(j,w+1) dp[i][j] = -1;
  REP(i,n+1) z[i].init(w+2);

  dp[0][0] = 0;
  z[0].update(0, 0);

  for(int i = 0; i < n; i++) {
    REP(j,w+1) dp[i+1][j] = dp[i][j];
    REP(j,w+1) {
      int cl = max(0, j - (int)r[i]);
      int cr = max(0, j - (int)l[i] + 1);
      if (cl == cr) continue;

      ll val = z[i].query(cl, cr);
      if (val != -1) dp[i+1][j] = max(dp[i+1][j], val + v[i]);
    }
    REP(j,w+1) z[i+1].update(j, dp[i+1][j]);
  }

	if (dp[n][w] == -1) cout << -1 << endl;
	else cout << dp[n][w] << endl;

  return;
}

int main() {
  cin >> w >> n;
  l.resize(n);
  r.resize(n);
  v.resize(n);
  REP(i,n) cin >> l[i] >> r[i] >> v[i];

  solve();
  return 0;
}