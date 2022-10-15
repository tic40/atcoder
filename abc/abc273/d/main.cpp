#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  int rs,cs; cin >> rs >> cs;
  rs--; cs--;

  map<int,set<int>> hblocks, vblocks; // 垂直方向
  int n; cin >> n;
  REP(i,n) {
    int a,b; cin >> a >> b;
    a--; b--;
    hblocks[a].insert(b);
    vblocks[b].insert(a);
  }

  int nh = rs, nw = cs;
  int q; cin >> q;
  REP(_,q) {
    char d; int l;
    cin >> d >> l;

    if (d == 'L') { // 左
      int ni = 0;
      if (hblocks[nh].size()) {
        auto it = hblocks[nh].upper_bound(nw);
        if (it != hblocks[nh].begin()) {
          it--;
          ni = *it+1;
        }
      }
      nw = max(ni, nw-l);

    } else if (d == 'R') { // 右
      int ni = w-1;
      if (hblocks[nh].size()) {
        auto it = hblocks[nh].upper_bound(nw);
        if (it != hblocks[nh].end()) ni = *it-1;
      }
      nw = min(ni, nw+l);

    } else if (d == 'U') { // 上
      int ni = 0;
      if (vblocks[nw].size()) {
        auto it = vblocks[nw].upper_bound(nh);
        if (it != vblocks[nw].begin()) {
          it--;
          ni = *it+1;
        }
      }
      nh = max(ni, nh-l);

    } else if (d == 'D') { // 下
      int ni = h-1;
      if (vblocks[nw].size())  {
        auto it = vblocks[nw].upper_bound(nh);
        if (it != vblocks[nw].end()) ni = *it-1;
      }
      nh = min(ni, nh+l);
    }

    cout << nh+1 << " " << nw+1 << endl;
  }
  return 0;
}