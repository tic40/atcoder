#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using PP = pair<P,P>;

const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  vector<P> p;
  REP(i,n) REP(j,n) if (s[i][j] == 'P') p.emplace_back(i,j);

  auto add = [&](int dir, P p) -> P {
    auto [i,j] = p;
    int ni = i + di[dir];
    int nj = j + dj[dir];
    ni = min(ni,n-1); ni = max(ni,0);
    nj = min(nj,n-1); nj = max(nj,0);
    if (s[ni][nj] == '#') { ni = i; nj = j; }
    return P(ni,nj);
  };

  auto to_i = [&](P p1, P p2) -> int {
    int res = 0;
    res = res * n + p1.first;
    res = res * n + p1.second;
    res = res * n + p2.first;
    res = res * n + p2.second;
    return res;
  };

  vector<int> dist(n*n*n*n, 1e9);
  queue<PP> q;
  auto push = [&](P p1, P p2, int cost) -> void {
    q.emplace(p1,p2);
    dist[to_i(p1,p2)] = cost;
  };
  push(p[0],p[1],0);

  while(q.size()) {
    auto [p1,p2] = q.front(); q.pop();
    if (p1 == p2) { cout << dist[to_i(p1,p2)] << endl; return 0; }

    REP(i,4) {
      P np1 = add(i,p1), np2 = add(i,p2);
      if (dist[to_i(np1,np2)] != 1e9) continue;
      push(np1,np2,dist[to_i(p1,p2)]+1);
    }
  }

  cout << -1 << endl;
  return 0;
}