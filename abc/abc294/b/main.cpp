#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector a(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];
  vector<string> s(h);
  REP(i,h) REP(j,w) {
    char now = a[i][j] == 0 ? '.' : char('A'+a[i][j]-1);
    s[i].push_back(now);
  }
  REP(i,h) cout << s[i] << endl;
  return 0;
}