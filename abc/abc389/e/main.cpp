#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll m; cin >> n >> m;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  ll tot, num;
  auto judge = [&](ll c) {
    tot = num = 0;
    REP(i,n) {
      ll k = ((c-1) /p[i]+1)/2;
      if (k <= 0) continue;
      if (m/k/k/p[i] == 0) return false;
      tot += k*k*p[i];
      num += k;
      if (tot > m) return false;
    }
    return true;
  };

  ll ok = 1, ng = m+1;
  while(ng-ok>1) {
    ll mid = (ok+ng)/2;
    if (judge(mid)) ok = mid;
    else ng = mid;
  }

  judge(ok);
  num += (m-tot)/ok;
  cout << num << endl;
  return 0;
}