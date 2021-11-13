#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using P = pair<int,int>;

void chmax(int& x, int y) { x = max(x,y); }

int h,w,n;
int main() {
  cin >> h >> w >> n;
  map<int,vector<P>> mp;
  map<P,int> cell;

  REP(i,n) {
    int r,c,a;
    cin >> r >> c >> a;
    r--; c--;
    // 大きい値から見ていくためにaではなく-aをkeyにする
    mp[-a].emplace_back(r,c);
    cell[P(r,c)] = i;
  }

  vector<int> ans(n);
  map<int,int> mxr,mxc;

  for(auto [_, ps]: mp) {
    for(auto [r,c]: ps) {
      int now = max(mxr[r],mxc[c]);
      ans[cell[P(r,c)]] = now;
    }
    for(auto [r,c]: ps) {
      int now = ans[cell[P(r,c)]];
      chmax(mxr[r], now+1);
      chmax(mxc[c], now+1);
    }
  }

  REP(i,n) cout << ans[i] << endl;
  return 0;
}