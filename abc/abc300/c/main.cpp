#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

const vector<P> m1 = { {1,1}, {1,-1}, {-1,1}, {-1,-1} };
int main() {
  int h,w; cin >> h >> w;
  vector<string> c(h);
  REP(i,h) cin >> c[i];
  int n = min(h,w);

  auto is_x = [&](int i, int j, int n) {
    if (c[i][j] == '.') return false;
    for(auto [vi,vj]: m1) {
      int ni = i + vi * n;
      int nj = j + vj * n;
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) return false;
      if (c[ni][nj] == '.') return false;
    }
    return true;
  };

  vector<int> ans(n+1);
  REP(i,h) REP(j,w) {
    if (!is_x(i,j,1)) continue;
    int now = 1;
    for(int k = 2; k <= n; k++) {
      if (!is_x(i,j,k)) break;
      now = k;
    }
    ans[now]++;
  }
  for(int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}