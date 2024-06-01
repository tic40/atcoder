#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<int> c(m);
  vector<char> r(m);
  vector a(m,vector<int>(n));
  REP(i,m) {
    cin >> c[i];
    REP(j,c[i]) { cin >> a[i][j]; a[i][j]--; }
    cin >> r[i];
  }

  int ans = 0;
  REP(bit, 1<<n) {
    vector<int> vec(n);
    REP(i,n) if (bit >> i & 1) vec[i] = 1;

    auto check = [&](int i) {
      int cnt = 0;
      REP(j,c[i]) if (vec[a[i][j]] == 1) cnt++;
      if (r[i] == 'o' && cnt < k) return false;
      if (r[i] == 'x' && cnt >= k) return false;
      return true;
    };

    bool ok = true;
    REP(i,m) if (!check(i)) ok = false;
    if (ok) ans++;
  }
  cout << ans << endl;
  return 0;
}