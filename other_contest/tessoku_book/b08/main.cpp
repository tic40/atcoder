#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const int mx = 1500;
  int n; cin >> n;
  vector s(mx+1,vector<int>(mx+1));
  REP(i,n) {
    int x,y; cin >> x >> y;
    s[x][y]++;
  }

  int q; cin >> q;
  REP(i,mx) REP(j,mx) s[i+1][j+1] += s[i+1][j];
  REP(i,mx) REP(j,mx) s[i+1][j+1] += s[i][j+1];
  REP(_,q) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = s[c][d];
    ans += s[a-1][b-1];
    ans -= s[a-1][d];
    ans -= s[c][b-1];
    cout << ans << endl;
  }

  return 0;
}