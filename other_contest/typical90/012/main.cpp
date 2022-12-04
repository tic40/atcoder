#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

const vector<P> m = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int main() {
  int h,w; cin >> h >> w;
  int q; cin >> q;
  vector a(h,vector<int>(w));
  auto hash = [&](int x, int y) { return x*w + y; };

  dsu uf(h*w);
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int r,c; cin >> r >> c;
      r--; c--;
      a[r][c] = 1;
      for(auto [dx,dy]: m) {
        int nx = r+dx;
        int ny = c+dy;
        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if (a[nx][ny] == 0) continue;
        uf.merge(hash(r,c), hash(nx,ny));
      }
    }

    if (t == 2) {
      int r1,c1,r2,c2;
      cin >> r1 >> c1 >> r2 >> c2;
      r1--; c1--; r2--; c2--;
      bool ok = a[r1][c1] && uf.same(hash(r1,c1), hash(r2,c2));
      cout << (ok ? "Yes" : "No") << endl;
    }
  }
  return 0;
}