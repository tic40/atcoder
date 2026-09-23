#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

void solve() {
  int n; cin >> n;
  vector<int> w(n),p(n);
  REP(i,n) cin >> w[i] >> p[i];
  vector<P> pa;
  ll s = accumulate(p.begin(),p.end(),0LL);
  vector<int> cost(n);
  REP(i,n) cost[i] = w[i]+p[i];
  sort(cost.begin(),cost.end());
  ll now = 0;
  int ans = 0;
  REP(i,n) {
    now += cost[i];
    if (s < now) break;
    ans++;
  }
  cout << ans << endl;
  return;
}

int main() {
  int t; cin >> t;
  REP(_,t) solve();
  return 0;
}
