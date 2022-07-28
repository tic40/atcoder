#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,C; cin >> n >> C;
  vector m(C,vector<int>(1e5+1));
  REP(i,n) {
    int s,t,c; cin >> s >> t >> c;
    s--; c--;
    m[c][s]++;
    m[c][t]--;
  }

  REP(i,C) REP(j,1e5) m[i][j+1] += m[i][j];
  REP(i,C) REP(j,1e5+1) m[i][j] = min(1,m[i][j]); // 被っているところは連続して録画できるので1にする

  int ans = 0;
  REP(i,1e5+1) {
    int cnt = 0;
    REP(j,C) cnt += m[j][i];
    ans = max(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}