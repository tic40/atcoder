#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int ans = 1e9;
  REP(x,10) {
    vector<bool> m(n);
    int cnt = 0;
    REP(t,n*10) {
      REP(i,n) if (!m[i]) {
        if (x == s[i][t%10] - '0') {
          m[i] = true;
          cnt++;
          break;
        }
      }
      if (cnt == n) { ans = min(ans,t); break; }
    }
  }

  cout << ans << endl;
  return 0;
}