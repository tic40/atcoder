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

int main() {
  int n; cin >> n;
  vector<vector<int>> xs(2), ys(2);
  REP(i,n) {
    int x,y; cin >> x >> y;
    // x,y を 45 度回転する
    int nx = x+y;
    int ny = x-y;
    xs[nx%2].push_back(nx);
    ys[nx%2].push_back(ny);
  }

  auto f = [&](vector<int> xs) {
    int n = xs.size();
    sort(xs.begin(),xs.end());
    ll res = 0;
    REP(i,n) {
      ll co = i - (n-i-1);
      res += co * xs[i];
    }
    return res/2;
  };

  ll ans = 0;
  REP(i,2) ans += f(xs[i]) + f(ys[i]);
  cout << ans << endl;
  return 0;
}