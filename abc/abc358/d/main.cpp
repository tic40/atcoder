#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  ll ans = 0;
  int p = 0;
  REP(i,m) {
    if (a[p] >= b[i]) {
      ans += a[p];
      p = p+1;
      continue;
    }
    auto it = lower_bound(a.begin()+p, a.end(),b[i]);
    if (it == a.end()) { cout << -1 << endl; return 0; }

    int idx = it-a.begin();
    ans += a[idx];
    p = idx+1;
  }
  cout << ans << endl;
  return 0;
}