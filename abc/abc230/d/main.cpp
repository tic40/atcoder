#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;
using P = pair<ll, ll>;

int main() {
  ll n,d;
  cin >> n >> d;
  vector<P> p(n);

  REP(i,n) {
    ll l,r; cin >> l >> r;
    l--; r--;
    p[i] = P{l,r};
  }

  // 終端が近いものからソート
  sort(p.begin(),p.end(),[](P& a, P& b) { return a.second < b.second; });

  ll ans = 0; // パンチを打った回数
  ll x = -1; // 最後にパンチを打った位置
  for (auto [l,r]: p) {
    if (x == -1 || x + d - 1 < l) {
      ans++;
      x = r;
    }
  }

  cout << ans << endl;
  return 0;
}