#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n),t(m);
  REP(i,n) cin >> s[i];
  REP(i,m) cin >> t[i];

  int ans = 0;
  REP(i,n) {
    string ts = s[i].substr(3);
    REP(j,m) if (ts == t[j]) { ans++; break; }
  }
  cout << ans << endl;
  return 0;
}