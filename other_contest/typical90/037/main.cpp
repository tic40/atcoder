#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
#define endl '\n'

class RangeMax {
public:
	int size_ = 1;
	vector<ll> dat;

	void init(int sz) {
		while (size_ <= sz) size_ *= 2;
		dat.resize(size_ * 2, -1);
	}
	void update(int pos, ll x) {
		pos += size_;
		dat[pos] = x;
		while (pos >= 2) {
			pos >>= 1;
			dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}
	ll query_(int l, int r, int a, int b, int u) {
		if (l <= a && b <= r) return dat[u];
		if (r <= a || b <= l) return -1;
		ll v1 = query_(l, r, a, (a + b) >> 1, u * 2);
		ll v2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
		return max(v1, v2);
	}
	ll query(int l, int r) {
		return query_(l, r, 0, size_, 1);
	}
};

int n,w;
vector<ll> l(1e4),r(1e4),v(1e4);
// dp[i][j] := i種類で香辛料の量がjのときの最大の価値
vector dp(501, vector<ll>(1e4+1,-1));
RangeMax z[501];

// DP + segment tree(range max)
void solve1() {
  REP(i,n+1) z[i].init(w+2);
  dp[0][0] = 0;
  z[0].update(0, 0);

  for(int i = 0; i < n; i++) {
    REP(j,w+1) dp[i+1][j] = dp[i][j];
    REP(j,w+1) {
      ll nl = max(0LL, j - r[i]);
      ll nr = max(0LL, j - l[i] + 1);
      if (nl == nr) continue;

      ll val = z[i].query(nl, nr);
      if (val != -1) dp[i+1][j] = max(dp[i+1][j], val+v[i]);
    }
    REP(j,w+1) z[i+1].update(j, dp[i+1][j]);
    REP(j,w+1) { cout << dp[i][j] << " "; }
    cout << endl;
  }

  cout << dp[n][w] << endl;
  return;
}

ll op(ll a, ll b) { return max(a,b); }
ll e() { return -1; }
// atcoder libraryを使う解法
void solve2() {
  segtree<ll, op, e> seg(w+1);
  seg.set(0,0);
  dp[0][0] = 0;

  REP(i,n) {
    REP(j,w+1) dp[i+1][j] = dp[i][j];
    REP(j,w+1) {
      ll nl = max(0LL, j - r[i]);
      ll nr = max(0LL, j - l[i]+1);
      if (nl == nr) continue;

      ll val = seg.prod(nl, nr);
      if (val != -1) dp[i+1][j] = max(dp[i+1][j], val+v[i]);
    }
    REP(j,w+1) seg.set(j, dp[i+1][j]);
  }

  cout << dp[n][w] << endl;
  return;
}

int main() {
  cin >> w >> n;
  REP(i,n) cin >> l[i] >> r[i] >> v[i];

  // solve1();
  solve2();
  return 0;
}