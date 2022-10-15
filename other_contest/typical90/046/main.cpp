#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  auto in = [&]() {
    vector<int> res(46);
    REP(i,n) { int x; cin >> x; res[x%46]++; }
    return res;
  };

  auto a = in();
  auto b = in();
  auto c = in();
  ll ans = 0;
  REP(i,46) REP(j,46) REP(k,46) {
    if ((i+j+k)%46) continue;
    ans += (ll)a[i] * b[j] * c[k];
  }

  cout << ans << endl;
  return 0;
}