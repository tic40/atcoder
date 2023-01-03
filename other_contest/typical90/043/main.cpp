#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;
using T = tuple<int,int,int,int>;
const int INF = numeric_limits<int>::max();

const vector<P> moves = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
  int h,w; cin >> h >> w;
  int rs,cs,rt,ct; cin >> rs >> cs >> rt >> ct;
  rs--; cs--; rt--; ct--;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  priority_queue<T, vector<T>, greater<T>> q;
  vector dist(h, vector(w, vector<int>(4,INF)));

  auto push = [&](int a, int b, int dir, int cost) {
    if (a < 0 || b < 0 || a >= h || b >= w) return;
    if (s[a][b] == '#') return;
    if (dist[a][b][dir] <= cost) return;
    q.emplace(cost, a, b, dir);
    dist[a][b][dir] = cost;
  };

  REP(i,4) push(rs,cs,i,0);
  while(q.size()) {
    auto [cost,x,y,dir] = q.top(); q.pop();
    REP(i,4) {
      auto [dx,dy] = moves[i];
      int nc = i == dir ? cost : cost+1;
      push(x+dx, y+dy, i, nc);
    }
  }

  int ans = *min_element(dist[rt][ct].begin(), dist[rt][ct].end());
  cout << ans << endl;
  return 0;
}