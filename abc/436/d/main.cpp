#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

vector<int> di = {-1,0,1,0};
vector<int> dj = {0,1,0,-1};

int main() {
  int h,w; cin >> h >> w;
  vector<string> g(h);
  REP(i,h) {
    string s; cin >> s;
    g[i] = s;
  }

  map<char,vector<P>> mp;
  REP(i,h) REP(j,w) if (g[i][j] != '.' && g[i][j] != '#') {
    mp[g[i][j]].emplace_back(i,j);
  }

  queue<P> q;
  vector dist(h,vector<int>(w,INF));

  auto push = [&](int i, int j, int d) {
    if (dist[i][j] <= d+1) return;
    dist[i][j] = d+1;
    q.emplace(i,j);
  };

  push(0,0,-1);
  while(!q.empty()) {
    auto [i,j] = q.front(); q.pop();

    if (g[i][j] != '.' && g[i][j] != '#') {
      for(auto [ni,nj]: mp[g[i][j]]) push(ni,nj,dist[i][j]);
      mp.erase(g[i][j]);
    }

    REP(k,4) {
      int ni = i+di[k];
      int nj = j+dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (g[ni][nj] == '#') continue;
      push(ni,nj,dist[i][j]);
    }
  }

  int d = dist[h-1][w-1];
  cout << (d == INF ? -1 : d) << endl;
  return 0;
}
