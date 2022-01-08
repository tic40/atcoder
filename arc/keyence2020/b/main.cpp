#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> x,l;

void solve() {
  vector<pair<int, int>> p(n);
  REP(i,n) {
    p[i] = { x[i]+l[i], max(0, x[i]-l[i]) };
  }
  sort(p.begin(), p.end());

  int ans = 0, cur = 0;
  REP(i,n) {
    if (cur <= p[i].second) {
      ans++;
      cur = p[i].first;
    }
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  x.resize(n);
  l.resize(n);
  REP(i,n) {
    cin >> x[i] >> l[i];
    x[i]--;
  }
  solve();

  return 0;
}