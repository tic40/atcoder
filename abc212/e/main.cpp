#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 998244353;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime MOD
  mint inv() const { return pow(MOD-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int n,m,k;
vector<vector<int>> to;

void solve() {
  vector<mint> dp(n);
  dp[0] = 1;

  REP(ki,k) {
    vector<mint> p(n);
    swap(p,dp);
    mint tot = 0; // 全ての合計
    REP(i,n) tot += p[i];

    REP(i,n) {
      // 途切れを考慮しない合計
      dp[i] = tot;
      // 隣接から途切れている分を引く
      for(int u: to[i]) dp[i] -= p[u];
      // 自分自身も合計に含まれているので引く
      dp[i] -= p[i];
      cout << "tot: " << tot << endl;
      REP(i,n) cout << dp[i] << " ";
      cout << endl;
    }
  }

  cout << dp[0] << endl;
  return;
}

int main() {
  cin >> n >> m >> k;
  to.resize(n);
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  solve();
  return 0;
}