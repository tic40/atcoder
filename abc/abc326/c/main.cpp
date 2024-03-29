#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  int ans = 0;
  REP(i,n) {
    int r = lower_bound(a.begin(),a.end(),a[i]+m) - a.begin();
    ans = max(ans, r - i);
  }
  cout << ans << endl;
  return 0;
}