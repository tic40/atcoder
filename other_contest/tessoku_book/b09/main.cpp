#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const int mx = 1500;
  int n; cin >> n;
  vector s(mx+1,vector<int>(mx+1));
  REP(i,n) {
    int a,b,c,d; cin >> a >> b >> c >> d;
    s[a][b]++;
    s[a][d]--;
    s[c][b]--;
    s[c][d]++;
  }

  REP(i,mx+1) REP(j,mx) s[i][j+1] += s[i][j];
  REP(i,mx) REP(j,mx+1) s[i+1][j] += s[i][j];
  int ans = 0;
  REP(i,mx+1) REP(j,mx+1) if (s[i][j] >= 1) ans++;
  cout << ans << endl;
  return 0;
}