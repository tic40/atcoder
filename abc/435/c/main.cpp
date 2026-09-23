#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int now = a[0];
  int ans = 1;
  for(int i = 1; i < n; i++) {
    now--;
    if (now <= 0) break;
    now = max(now,a[i]);
    ans++;
  }
  cout << ans << endl;
  return 0;
}
