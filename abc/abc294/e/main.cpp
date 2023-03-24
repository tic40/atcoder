#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  ll l;
  vector<int> n(2);
  cin >> l >> n[0] >> n[1];

  // events[i] := 時間 i の event{ v1 or v2, 数値　}
  vector<pair<ll,P>> events;
  REP(i,2) {
    ll t = 0;
    REP(j,n[i]) {
      int v; ll len;
      cin >> v >> len;
      events.emplace_back(t,P(i,v));
      t += len;
    }
  }
  // event sort
  sort(events.begin(),events.end());
  events.emplace_back(l,P(0,0));

  vector<int> val(2);
  ll ans = 0, pt = 0;
  for(auto [t,p]: events) {
    if (val[0] == val[1]) ans += t-pt;
    auto [i,v] = p;
    val[i] = v;
    pt = t;
  }

  cout << ans << endl;
  return 0;
}