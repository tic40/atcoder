#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];

  int ans = 0;
  REP(l,n) for(int r = l+1; r < n+1; r++) {
    int tot = s[r]-s[l];
    bool ok = true;
    for(int i = l; i < r; i++) {
      if (tot % a[i] == 0) ok = false;
    }
    if (ok) ans++;
  }
  cout << ans << endl;
  return 0;
}
