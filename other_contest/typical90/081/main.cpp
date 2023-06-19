#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector s(5001,vector<int>(5001));
  REP(i,n) { int a,b; cin >> a >> b; s[a][b]++; }
  REP(i,5000) REP(j,5000) s[i+1][j] += s[i][j];
  REP(i,5000) REP(j,5000) s[i][j+1] += s[i][j];

  int ans = 0;
  REP(i,5000) REP(j,5000) {
    int ri = min(5000,i+k+1);
    int rj = min(5000,j+k+1);
    int now = s[i][j];
    now -= s[ri][j];
    now -= s[i][rj];
    now += s[ri][rj];
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}