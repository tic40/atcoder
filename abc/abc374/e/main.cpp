#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,x; cin >> n >> x;
  vector<P> s(n),t(n);
  REP(i,n) {
    cin >> s[i].first >> s[i].second;
    cin >> t[i].first >> t[i].second;
    // 効率が良い方を s にしておく
    // b/q > a/p = b * p > a * q
    if (t[i].first * s[i].second > s[i].first * t[i].second) swap(s[i],t[i]);
  }

  auto f = [&](int m) {
    ll cost = 0;
    REP(i,n) {
      ll now = LINF;
      REP(j,100) {
        // k := s 側で作る個数
        // m - t 側で作る個数している
        int k = max(m - t[i].first * j, 0);
        k = (k+s[i].first - 1) / s[i].first;
        now = min(now, t[i].second * j + (ll)s[i].second * k);
      }
      cost += now;
      if (cost > x) return false;
    }
    return cost <= x;
  };

  int ok = 0, ng = 1e9+5;
  while(abs(ok-ng) > 1) {
    int mid = (ok+ng) / 2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}