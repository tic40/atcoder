#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector s(5001,vector<int>(5001));
  REP(i,n) {
    int a,b; cin >> a >> b;
    s[a][b]++;
  }

  REP(i,5000) REP(j,5000) s[i+1][j] += s[i][j];
  REP(i,5000) REP(j,5000) s[i][j+1] += s[i][j];

  int ans = 0;
  REP(i,5000) REP(j,5000) {
    if (i+k+1 > 5000 || j+k+1 > 5000) break;

    int now = s[i+k+1][j+k+1];
    now -= s[i+k+1][j];
    now -= s[i][j+k+1];
    now += s[i][j];
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}