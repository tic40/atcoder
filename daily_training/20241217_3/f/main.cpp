#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;

  vector<P> pa(m);
  REP(i,m) cin >> pa[i].first, pa[i].first--;
  REP(i,m) cin >> pa[i].second;
  sort(pa.begin(),pa.end());
  if (pa[0].first != 0) { cout << -1 << endl; return 0; }
  if (pa.back().first != n-1) {
    pa.emplace_back(n-1,0);
    m += 1;
  }

  ll ans = 0;
  ll rem = 0;
  int px = 0;
  REP(i,m) {
    auto [x,a] = pa[i];
    ll d = max(0,x-px-1);
    rem -= d;
    ans += (ll)(1+d)*d/2;
    if (rem < 0) { cout << -1 << endl; return 0; }
    ans += rem * (x-px);
    rem += a-1;

    px = x;
  }
  if (rem != 0) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}