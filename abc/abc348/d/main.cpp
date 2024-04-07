#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using P2 = pair<int,P>;
const vector<P> moves = { {-1,0},{0,1},{1,0},{0,-1} };

int main() {
  int h,w; cin >> h >> w;
  vector<string> a(h);
  REP(i,h) cin >> a[i];
  int n; cin >> n;
  vector item(h,vector<int>(w));
  REP(i,n) {
    int r,c,e; cin >> r >> c >> e;
    r--; c--;
    item[r][c] = e;
  }

  auto bfs = [&]() {
    vector dist(h,vector<int>(w,-1));
    // エネルギー値の降順に取り出すキュー
    // P2 := { エネルギー, 位置(i,j) }
    priority_queue<P2, vector<P2>, less<P2>> q;
    // スタート地点をキューへ
    REP(i,h) REP(j,w) if (a[i][j] == 'S') q.emplace(0,P(i,j));

    while(q.size()) {
      auto [e,pa] = q.top(); q.pop();
      auto [i,j] = pa;
      if (a[i][j] == 'T') return true; // goal

      // アイテムは貪欲に使って良い
      e = max(e,item[i][j]);
      if (e <= 0 || dist[i][j] >= e) continue;
      dist[i][j] = e;
      for(auto [di,dj]: moves) {
        int ni = i+di, nj = j+dj;
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (a[ni][nj] == '#') continue;
        q.emplace(e-1,P(ni,nj));
      }
    }
    return false;
  };

  cout << (bfs() ? "Yes" : "No") << endl;
  return 0;
}