#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;

int n,q;
vector<ll> c;

int main() {
  cin >> n;
  c.resize(n);
  REP(i,n) cin >> c[i];
  cin >> q;

  ll tot_min = LINF, odd_min = LINF;
  REP(i,n) tot_min = min(tot_min, c[i]);
  REP(i,n) if (i%2 == 0) odd_min = min(odd_min, c[i]);

  // 売った枚数
  ll odd_cnt = 0, tot_cnt = 0;
  vector<ll> cnt(n);

  REP(i,q) {
    int t,x; cin >> t >> x;

    if (t == 1) { // 単品販売
      ll y; cin >> y;
      x--;

      ll cur = c[x];
      cur -= cnt[x];
      cur -= tot_cnt;
      if (x%2 == 0) cur -= odd_cnt;
      if (cur < y) continue; // 在庫なし

      cur -= y;
      cnt[x] += y;
      tot_min = min(tot_min, cur);
      if (x%2 == 0) odd_min = min(odd_min, cur);

    } else if (t == 2) { // セット販売
      if (odd_min < x) continue; // 在庫なし
      odd_cnt += x;
      odd_min -= x;
      tot_min = min(tot_min, odd_min);
    } else {
      if (tot_min < x) continue; // 在庫なし
      tot_cnt += x;
      tot_min -= x;
      odd_min -= x;
    }
  }

  ll ans = 0;
  ans += tot_cnt * n;
  ans += odd_cnt * ((n+1) / 2);
  for(ll v: cnt) ans += v;

  cout << ans << endl;
  return 0;
}