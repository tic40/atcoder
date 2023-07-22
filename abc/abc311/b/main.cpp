#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,d; cin >> n >> d;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int ans = 0, now = 0;
  REP(i,d) {
    bool ok = true;
    REP(j,n) if (s[j][i] == 'x') ok = false;
    if (ok) now++;
    else now = 0;
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}