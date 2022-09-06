#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  int ans = 0;
  REP(i,h-1) REP(j,w-1) {
    int cnt = 0;
    REP(k,2) REP(l,2) if (s[i+k][j+l] == '#') cnt++;
    if (cnt == 1 || cnt == 3) ans++;
  }

  cout << ans << endl;
  return 0;
}