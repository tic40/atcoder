#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

template<typename T=int>
struct CC {
  bool initialized;
  vector<T> xs;
  CC(): initialized(false) {}
  void add(T x) { xs.push_back(x);}
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    initialized = true;
  }
  int operator()(T x) {
    if (!initialized) init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {
    if (!initialized) init();
    return xs[i];
  }
  int size() {
    if (!initialized) init();
    return xs.size();
  }
};

struct P {
  ll t, r;
  P(ll t=0, ll r=0): t(t), r(r) {}
  bool operator<(const P& p) const {
    if (t != p.t) return t < p.t;
    return r > p.r;
  }
  P add(ll cost, ll earn) {
    if (r >= cost) return P(t+1,r-cost);
    cost -= r;
    ll num = (cost+earn-1)/earn;
    return P(t+num+1, num*earn-cost);
  }
};

int main() {
  int n; cin >> n;
  vector p(n,vector<int>(n));
  vector r(n,vector<int>(n-1));
  vector d(n-1,vector<int>(n));
  REP(i,n) REP(j,n) cin >> p[i][j];
  REP(i,n) REP(j,n-1) cin >> r[i][j];
  REP(i,n-1) REP(j,n) cin >> d[i][j];
  vector dp(80,vector(80,vector<P>(80*80)));

  CC cc;
  REP(i,n) REP(j,n) cc.add(p[i][j]);
  int m = cc.size();
  REP(i,n)REP(j,n) p[i][j] = cc(p[i][j]);

  // dp[i][j][k] := i,j 地点にいるときに 今までの p の max が k のときの最小の P
  REP(i,n) REP(j,n) REP(k,m) dp[i][j][k] = P(LINF,0);
  dp[0][0][p[0][0]] = P(0,0);

  REP(i,n) REP(j,n) REP(k,m) {
    P x = dp[i][j][k];
    if (x.t == LINF) continue;
    if (j+1 < n) {
      int nk = max(k,p[i][j+1]);
      chmin(dp[i][j+1][nk], x.add(r[i][j],cc[k]));
    }
    if (i+1 < n) {
      int nk = max(k,p[i+1][j]);
      chmin(dp[i+1][j][nk], x.add(d[i][j],cc[k]));
    }
  }

  ll ans = LINF;
  REP(k,m) ans = min(ans, dp[n-1][n-1][k].t);
  cout << ans << endl;
  return 0;
}