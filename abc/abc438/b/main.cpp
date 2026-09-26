#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  string s,t; cin >> s >> t;

  int ans = 1e9;
  REP(i,n) if (i+m-1 < n) {
    int cnt = 0;
    REP(j,m) {
      int d = (s[i+j]-'0') - (t[j]-'0');
      cnt += (d + 10) % 10;
    }
    ans = min(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}
