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
  vector<int> t(d);
  REP(i,d) { cin >> t[i]; t[i]--; }

  auto solve = [&]() {
    int ans = 0;
    vector<int> last(26);
    REP(i,d) {
      ans += s[i][t[i]];
      last[t[i]] = i+1;
      REP(j,26) ans -= c[j] * ((i+1) - last[j]);
    }
    return ans;
  };

  int m; cin >> m;
  REP(_,m) {
    int td,tq; cin >> td >> tq;
    td--; tq--;
    t[td] = tq;
    cout << solve() << endl;
  }

  return 0;
}