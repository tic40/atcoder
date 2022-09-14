#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
using P = pair<int,int>;

const vector<P> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(50);
  REP(i,h) cin >> s[i];

  int si = -1, sj = -1;
  int ai = -1, aj = -1;
  int gi = -1, gj = -1;
  REP(i,h) REP(j,w) {
    if (s[i][j] == 's') { si = i; sj = j; }
    if (s[i][j] == 'a') { ai = i; aj = j; }
    if (s[i][j] == 'g') { gi = i; gj = j; }
  }

  vector dist(50,vector(50, vector(50, vector<int>(50,INF))));
  dist[si][sj][ai][aj] = 0;

  queue<pair<P,P>> q;
  q.emplace(P{si,sj}, P{ai,aj});

  auto can_move = [&](int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return false;
    if (s[x][y] == '#') return false;
    return true;
  };

  while(q.size()) {
    auto [cs,ca] = q.front(); q.pop();
    auto [csi,csj] = cs;
    auto [cai,caj] = ca;

    for(auto [dx,dy]: moves) {
      int nsi = csi+dx, nsj = csj+dy;
      if (!can_move(nsi,nsj)) continue;

      int nai = cai, naj = caj;
      // 移動先が荷物マスのとき荷物を動かす
      if (nsi == nai && nsj == naj) {
        nai += dx, naj += dy;
        if (!can_move(nai,naj)) continue;
      }

      int ndist = dist[csi][csj][cai][caj]+1;
      if (dist[nsi][nsj][nai][naj] > ndist) {
        dist[nsi][nsj][nai][naj] = ndist;
        q.emplace(P{nsi,nsj}, P{nai,naj});
      }
    }
  }

  int ans = INF;
  REP(i,h) REP(j,w) ans = min(ans,dist[i][j][gi][gj]);
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}