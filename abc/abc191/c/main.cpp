#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int h,w;
  cin >> h >> w;
  char s[h][w];
  REP(i,h) REP(j,w) { cin >> s[i][j]; }

  int ans = 0;
  REP(i,h-1) REP(j,w-1) {
    int cnt = 0;
    REP(k,2) REP(l,2) {
      if (s[k+i][l+j] == '#') cnt++;
    }
    if (cnt%2) ans++;
  }

  cout << ans << endl;
  return 0;
}