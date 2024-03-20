#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

struct V {
  ll x,y;
  V(ll x=0, ll y=0): x(x),y(y) {};
  V operator-(const V& a) const { return V(x-a.x, y-a.y); }
  // 外積
  ll cross(const V& a) const { return x*a.y - y*a.x; }
  // ccw: counter clockwise
  ll ccw (const V& a) const {
    ll area = cross(a);
    if (area > 0) return 1; // 反時計周り
    if (area < 0) return -1; // 時計周り
    return 0; // 一直線上
  }
};

int main() {
  int n; cin >> n;
  vector<ll> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  int ans = 0;
  auto dfs = [&](auto self, int i, vector<int> v) {
    if (v.size() == 3) {
      vector<V> vec;
      for(auto k: v) vec.emplace_back(x[k],y[k]);
      vec[1] = vec[1]-vec[0];
      vec[2] = vec[2]-vec[0];
      if (vec[1].cross(vec[2]) != 0) ans++;
      return;
    }
    if (i >= n) return;

    self(self,i+1,v);
    v.push_back(i);
    self(self,i+1,v);
  };

  dfs(dfs,0,vector<int>());
  cout << ans << endl;
  return 0;
}