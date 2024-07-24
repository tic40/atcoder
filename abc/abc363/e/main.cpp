#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

const vector<int> di = {1,-1,0,0};
const vector<int> dj = {0,0,1,-1};

int main() {
  int h,w,y; cin >> h >> w >> y;
  vector ps(y, vector<P>());
  REP(i,h) REP(j,w) {
    int a; cin >> a; a--;
    if (a < y) ps[a].emplace_back(i+1,j+1);
  }

  // true: 残っている
  // +2 しているのは番兵を周囲 1 マス分取るため
  vector remain(h+2,vector<bool>(w+2));
  // true: 海面以下
  vector under(h+2,vector<bool>(w+2,true));
  // 初期状態
  REP(i,h) REP(j,w) {
    remain[i+1][j+1] = true;
    under[i+1][j+1] = false;
  }

  int ans = h*w;
  REP(year,y) {
    queue<P> q;
    for(auto [i,j]: ps[year]) {
      under[i][j] = true;
      bool sink = false;
      REP(v,4) {
        int ni = i+di[v];
        int nj = j+dj[v];
        if (!remain[ni][nj]) sink = true;
      }
      if (sink) {
        remain[i][j] = false;
        q.emplace(i,j);
        ans--;
      }
    }

    while(q.size()) {
      auto [i,j] = q.front(); q.pop();
      REP(v,4) {
        int ni = i+di[v];
        int nj = j+dj[v];
        if (under[ni][nj] && remain[ni][nj]) {
          remain[ni][nj] = false;
          q.emplace(ni,nj);
          ans--;
        }
      }
    }
    cout << ans << endl;
  }
}