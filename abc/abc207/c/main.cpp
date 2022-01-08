#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> t;
vector<double> l,r;

void solve() {
  REP(i,n) {
    if (t[i] == 1) {
      // do nothing
    } else if (t[i] == 2) {
      r[i] -= 0.5;
    } else if (t[i] == 3) {
      l[i] += 0.5;
    } else {
      l[i] += 0.5;
      r[i] -= 0.5;
    }
  }

  int ans = 0;
  REP(i,n) {
    for (int j = i+1; j < n; j++) {
      if (max(l[i], l[j]) <= min(r[i], r[j])) ans++;
    }
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  t.resize(n); l.resize(n); r.resize(n);
  REP(i,n) cin >> t[i] >> l[i] >> r[i];

  solve();
  return 0;
}