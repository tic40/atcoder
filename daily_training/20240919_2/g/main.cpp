#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;
using T = tuple<int,int,int>;

const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];
  int n; cin >> n;
  vector g(h,vector<int>(w));
  REP(i,n) {
    int r,c,e; cin >> r >> c >> e;
    r--; c--;
    g[r][c] = e;
  }

  P start;
  REP(i,h) REP(j,w) if (s[i][j] == 'S') start = {i,j};

  vector visited(h,vector<int>(w,-1));
  priority_queue<T, vector<T>, less<T>> q;
  q.emplace(g[start.first][start.second],start.first,start.second);
  bool ok = false;
  while(q.size()) {
    auto [e,ci,cj] = q.top(); q.pop();
    if (e < 0) continue;
    e = max(e,g[ci][cj]);
    if (visited[ci][cj] >= e) continue;
    visited[ci][cj] = e;
    if (s[ci][cj] == 'T') { ok = true; break; }
    REP(i,4) {
      int ni = di[i]+ci;
      int nj = dj[i]+cj;
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      q.emplace(e-1,ni,nj);
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}