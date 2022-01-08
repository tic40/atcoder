#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 998244353;

struct mint {
  long long x;
  mint(long long x=0):x((x%MOD+MOD)%MOD){}
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
  mint pow(long long t) const {
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

struct Edge {
  int to,id;
  Edge() {}
  Edge(int to, int id): to(to), id(id) {}
};

int n,m,k;
vector<int> a;
vector<vector<Edge>> g;

void solve() {
  vector<int> c(n-1); // 各辺を何度訪れたか

  // 各辺からコマa[i] -> a[i+1] を最短経路で移動した場合に
  // コマの移動により各辺を何度通過するかをdfs数える
  REP(i,m-1) {
    int start = a[i]-1;
    int goal = a[i+1]-1;

    // ラムダ再帰dfs
    auto dfs = [&](auto& f, int v, int p = -1) {
      if (v == goal) return true;
      for(auto e: g[v]) {
        if (e.to == p) continue;
        if (f(f, e.to, v)) {
          c[e.id]++;
          return true;
        }
      }
      return false;
    };

    dfs(dfs, start);
  }

  // s: 各辺を通った数の合計
  int s = 0;
  REP(i,n-1) s += c[i];

  // 2*r = k+sより
  int r2 = k+s;

  if (r2 < 0 || s*2 < r2 || r2%2 == 1) {
    cout << 0 << endl;
    return;
  }

  int r = r2/2;
  vector<mint> dp(r+1);
  dp[0] = 1;
  for(int x: c) {
    for (int i = r-x; 0 <= i; --i) dp[i+x] += dp[i];
  }

  cout << dp[r] << endl;
  return;
}

int main() {
  cin >> n >> m >> k;
  a.resize(m);
  g.resize(n);
  REP(i,m) cin >> a[i];
  REP(i,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].emplace_back(b,i);
    g[b].emplace_back(a,i);
  }

  solve();
  return 0;
}