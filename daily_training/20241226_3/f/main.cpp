#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n),w(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> w[i];

  vector<int> b(n+1);
  int ans = 0;
  REP(i,n) {
    ans += min(b[a[i]],w[i]);
    b[a[i]] = max(b[a[i]],w[i]);
  }

  cout << ans << endl;
  return 0;
}