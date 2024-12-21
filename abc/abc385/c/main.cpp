#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  int ans = 1;
  for(int len = 1; len <= n; len++) {
    REP(i,n) {
      int now = 1;
      for(int j = i+len; j <= n; j+=len) {
        if (h[j] != h[i]) break;
        now++;
      }
      ans = max(ans,now);
    }
  }
  cout << ans << endl;
  return 0;
}