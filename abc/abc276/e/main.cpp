#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

const vector<pair<int,int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int main() {
  int h,w; cin >> h >> w;
  vector<string> c(h);
  REP(i,h) cin >> c[i];

  dsu uf(h*w);
  auto id = [&](int i, int j) { return i*w+j; };
  REP(i,h) REP(j,w) {
    if (c[i][j] != '.') continue;
    if (j+1 < w && c[i][j+1] == '.') uf.merge(id(i,j), id(i,j+1));
    if (i+1 < h && c[i+1][j] == '.') uf.merge(id(i,j), id(i+1,j));
  }

  int si, sj;
  REP(i,h) REP(j,w) if(c[i][j] == 'S') { si = i; sj = j; }
  bool ok = false;
  REP(i,4) for(int j = i+1; j < 4; j++) {
    int ai = si+d[i].first, aj = sj+d[i].second;
    int bi = si+d[j].first, bj = sj+d[j].second;
    if (ai < 0 || aj < 0 || ai >= h || aj >= w) continue;
    if (bi < 0 || bj < 0 || bi >= h || bj >= w) continue;
    if (uf.same(id(ai,aj), id(bi,bj))) ok = true;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}