#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w,n; cin >> h >> w >> n;
  vector s(h+1, vector<int>(w+1));
  REP(i,n) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    s[a][b]++;
    s[a][d+1]--;
    s[c+1][b]--;
    s[c+1][d+1]++;
  }

  REP(i,h) REP(j,w) s[i+1][j] += s[i][j];
  REP(i,h) REP(j,w) s[i][j+1] += s[i][j];

  REP(i,h) {
    REP(j,w) cout << s[i][j] << " ";
    cout << endl;
  }
  return 0;
}