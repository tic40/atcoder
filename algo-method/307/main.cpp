#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int ans = 0;
  REP(i,n) ans += max(0, a[i]);
  cout << ans << endl;
  return 0;
}