#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int h,w;
vector<string> s;
int hori[2000][2000]; // 横方向
int vert[2000][2000]; // 縦方向

void solve() {
  REP(i,h) REP(j,w) {
    if (s[i][j] == '#') continue;
    hori[i][j] = j == 0 ? 1 : hori[i][j-1]+1;
    vert[i][j] = i == 0 ? 1 : vert[i-1][j]+1;
  }

  // 逆方向からmaxを取っていく
  for(int i=h-2; 0<=i; i--) for(int j=w-2; 0<=j; j--) {
    if (s[i][j] == '#') continue;
    hori[i][j] = max(hori[i][j], hori[i][j+1]);
    vert[i][j] = max(vert[i][j], vert[i+1][j]);
  }

  int ans = 0;
  REP(i,h) REP(j,w) ans = max(ans, hori[i][j] + vert[i][j]-1);
  cout << ans << endl;
  return;
}

int main() {
  cin >> h >> w;
  s.resize(h);
  REP(i,h) cin >> s[i];

  solve();
  return 0;
}