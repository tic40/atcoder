#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,d; cin >> n >> d;
  vector<int> t(n),l(n);
  REP(i,n) cin >> t[i] >> l[i];
  for(int k = 1; k <= d; k++) {
    int ans = 0;
    REP(i,n) ans = max(ans,t[i]*(l[i]+k));
    cout << ans << endl;
  }
  return 0;
}