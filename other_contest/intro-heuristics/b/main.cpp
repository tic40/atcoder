#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int d; cin >> d;
  vector<int> c(26);
  REP(i,26) cin >> c[i];
  vector s(d,vector<int>(26));
  REP(i,d) REP(j,26) cin >> s[i][j];
  vector<int> last(26);
  int ans = 0;
  REP(i,d) {
    int t; cin >> t; t--;
    ans += s[i][t];
    last[t] = i+1;
    REP(j,26) ans -= c[j] * ((i+1) - last[j]);
    cout << ans << endl;
  }
  return 0;
}