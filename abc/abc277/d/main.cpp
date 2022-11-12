#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll tot = accumulate(a.begin(),a.end(),0LL);
  if (n == 1) { cout << 0 << endl; return 0; }

  sort(a.begin(),a.end());
  a.insert(a.end(),a.begin(),a.end());
  int n2 = a.size();

  vector<ll> s(n2+1);
  REP(i,n2) s[i+1] = s[i]+a[i];

  vector<bool> b(n2+1); // +1して末尾に番兵を置く
  REP(i,n2-1) {
    if (a[i+1] == a[i] || a[i+1] == (a[i]+1)%m) b[i+1] = true;
  }

  int p = -1;
  ll ans = tot - a.back();
  REP(i,n2+1) {
    if (b[i]) {
      if (p == -1) p = i-1;
    } else {
      if (p == -1) continue;
      ll now = s[i] - s[p];
      ans = min(ans, max(0LL,tot-now));
      p = -1;
    }
  }

  cout << ans << endl;
  return 0;
}