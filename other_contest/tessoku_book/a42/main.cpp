#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector s(101,vector<int>(101));
  REP(i,n) {
    int x,y; cin >> x >> y;
    s[x][y]++;
  }

  REP(i,100) REP(j,100) {
    s[i+1][j+1] += s[i+1][j];
    s[i+1][j+1] += s[i][j+1];
    s[i+1][j+1] -= s[i][j];
  }

  int ans = 0;
  REP(i,101) REP(j,101) {
    if (i+k+1 > 100 || j+k+1 > 100) continue;
    int now = s[i][j];
    now -= s[i][j+k+1];
    now -= s[i+k+1][j];
    now += s[i+k+1][j+k+1];
    ans = max(ans,now);
  }

  cout << ans << endl;
  return 0;
}