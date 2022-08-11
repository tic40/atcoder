#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

const vector<P> dir = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int main() {
  int h,w,n,m;
  cin >> h >> w >> n >> m;
  vector<int> a(n),b(n);
  vector block(h, vector<bool>(w));
  REP(i,n) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  REP(i,m) {
    int c,d; cin >> c >> d;
    c--; d--;
    block[c][d] = true;
  }

  vector light(h, vector<int>(w));
  // 4方向をそれぞれ試す
  REP(k,4) {
    auto [dx,dy] = dir[k];
    REP(i,n) {
      int nx = a[i], ny = b[i];
      while(1) {
        if (nx < 0 || h <= nx || ny < 0 || w <= ny) break;
        if (block[nx][ny]) break;
        if (light[nx][ny] == k+1) break;
        light[nx][ny] = k+1;
        nx += dx; ny += dy;
      }
    }
  }

  int ans = 0;
  REP(i,h) REP(j,w) if (light[i][j]) ans++;
  cout << ans << endl;
  return 0;
}