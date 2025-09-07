#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const vector<int> di = {0,-1,0,1};
const vector<int> dj = {1,0,-1,0};

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  auto f = [&](int x, int y) {
    int cnt = 0;
    REP(i,4) {
      int ni = x+di[i];
      int nj = y+dj[i];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '#') cnt++;
    }
    return cnt == 2 || cnt == 4;
  };

  int ok = 1;
  REP(i,h) REP(j,w) if (s[i][j] == '#') ok &= f(i,j);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}