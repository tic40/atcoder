#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  int ans = 1e9;
  REP(l,n) {
    int r = l + n - k - 1;
    if (r >= n) break;
    ans = min(ans,a[r]-a[l]);
  }
  cout << ans << endl;
  return 0;
}