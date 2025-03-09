#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> b(n),w(m);
  REP(i,n) cin >> b[i];
  REP(i,m) cin >> w[i];
  REP(i,n-m) w.push_back(0);
  sort(b.rbegin(),b.rend());
  sort(w.rbegin(),w.rend());

  ll ans = 0, now = 0;
  REP(i,n) {
    now += b[i] + max(0,w[i]);
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}
