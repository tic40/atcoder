#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

const vector<P> moves = { {1,0},{0,1},{-1,0},{0,-1} };

int h,w,q;
int get_hash(int x, int y) { return x*w + y; }

int main() {
  cin >> h >> w >> q;
  dsu uf(h*w);
  vector a(h,vector<bool>(w));

  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int r,c; cin >> r >> c;
      r--; c--;
      a[r][c] = true;
      for(auto [dx,dy]: moves) { // 上下左右
        int nx = r+dx, ny = c+dy;
        if (nx >= 0 && ny >= 0 && nx < h && ny < w && a[nx][ny]) {
          uf.merge(get_hash(r,c), get_hash(nx,ny));
        }
      }
    } else {
      int ra,ca,rb,cb;
      cin >> ra >> ca >> rb >> cb;
      ra--; ca--; rb--; cb--;
      if (a[ra][ca] && a[rb][cb] && uf.same(get_hash(ra,ca), get_hash(rb,cb))) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}