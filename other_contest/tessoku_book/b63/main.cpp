#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const vector<P> moves = { { 1,0 }, { -1,0 }, { 0,1 }, { 0,-1 } };

int main() {
  int r,c; cin >> r >> c;
  int sy,sx,gy,gx; cin >> sy >> sx >> gy >> gx;
  sy--; sx--; gy--; gx--;

  vector<string> a(r);
  REP(i,r) cin >> a[i];

  queue<P> q;
  vector dist(r,vector<int>(c,1e9));

  auto push = [&](int i, int j, int nd) {
    if (i < 0 || j < 0 || i >= r || j >= c) return;
    if (a[i][j] == '#') return;
    if (nd >= dist[i][j]) return;
    dist[i][j] = nd;
    q.emplace(i,j);
  };

  push(sy,sx,0);
  while(q.size()) {
    auto [i,j] = q.front(); q.pop();
    int nd = dist[i][j]+1;
    for(auto [dy,dx]: moves) push(dy+i,dx+j,nd);
  }

  cout << dist[gy][gx] << endl;
  return 0;
}