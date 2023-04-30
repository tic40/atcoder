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

  auto f = [&](int i, int j) {
    if (c[i][j] == '.') return 0;
    int res = 0;
    for(int k = 1; k <= n; k++) {
      for(auto [vi,vj]: m1) {
        int ni = i + vi * k;
        int nj = j + vj * k;
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) return res;
        if (c[ni][nj] == '.') return res;
      }
      res = k;
    }
    return res;
  };

  vector<int> ans(n+1);
  REP(i,h) REP(j,w) ans[f(i,j)]++;
  REP(i,n) cout << ans[i+1] << " ";
  return 0;
}