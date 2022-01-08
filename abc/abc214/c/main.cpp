#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int n;
vector<int> s,t;

void solve() {
  vector<int> ans(n, INF);

  REP(i,n) ans[i] = min(ans[i], t[i]);
  REP(i,n*2) {
    int ci = i % n;
    int ni = (ci+1) % n;
    ans[ni] = min( ans[ni], ans[ci]+s[ci]);
  }

  REP(i,n) cout << ans[i] << endl;
  return;
}

int main() {
  cin >> n;
  s.resize(n);
  t.resize(n);

  REP(i,n) cin >> s[i];
  REP(i,n) cin >> t[i];

  solve();
  return 0;
}