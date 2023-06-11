#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  // l: 左端, r: 右端, b: 下端, t: 上端
  int l = 1e9, r = 0;
  int b = 0, t = 1e9;
  REP(i,h) REP(j,w) {
    if (s[i][j] != '#') continue;
    l = min(l,j);
    r = max(r,j);
    t = min(t,i);
    b = max(b,i);
  }

  for(int i = t; i <= b; i++) for(int j = l; j <= r; j++) {
    if (s[i][j] == '#') continue;
    cout << i+1 << " " << j+1 << endl;
    return 0;
  }
}