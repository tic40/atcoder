#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> s(n-1),x(m);
  REP(i,n-1) cin >> s[i];
  REP(i,m) cin >> x[i];

  map<ll, int> cnt;
  ll a = 0;
  int c = 1;
  REP(i,n) {
    REP(j,m) cnt[(x[j]-a)*c]++;
    if (i == n-1) break;
    a = s[i] - a;
    c = -c;
  }

  int ans = 0;
  for(auto [_,c]: cnt) ans = max(ans,c);
  cout << ans << endl;
  return 0;
}