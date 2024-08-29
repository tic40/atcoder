#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

struct D {
  ll val; int col;
  D(ll val = -LINF, int col = -1): val(val),col(col) {}
};

struct Top2 {
  D a,b;
  Top2(D a = D(), D b = D(-LINF,-2)): a(a),b(b) {}
  void operator<=(D d) {
    if (b.val < d.val) {
      swap(b,d);
      if (a.val < b.val) swap(a,b);
    }
    if (a.col == b.col) b = d;
  }
  void operator<=(Top2 x) {
    *this <= x.a;
    *this <= x.b;
  }
  ll get(int c) {
    return a.col == c ? b.val : a.val;
  }
};

int main() {
  int n,k; cin >> n >> k;
  vector<int> c(n),v(n);
  REP(i,n) cin >> c[i] >> v[i];

  vector<Top2> dp(k+1);
  dp[0] = Top2(D(0,-1));

  REP(i,n) {
    vector<Top2> old(k+1);
    swap(old,dp);
    REP(j,k+1) {
      if (j < k) dp[j+1] = old[j];
      dp[j] <= D(old[j].get(c[i]) + v[i], c[i]);
    }
  }

  ll ans = dp[k].a.val;
  if (ans < 0) ans = -1;
  cout << ans << endl;
  return 0;
}