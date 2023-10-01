#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = 1e9;

int main() {
  vector p(3,vector<string>(4));
  REP(i,3) REP(j,4) cin >> p[i][j];

  auto rorate90 = [&](vector<string> &s) -> void {
    auto t = s;
    REP(i,4) REP(j,4) t[i][j] = s[3-j][i];
    s = t;
  };

  auto reset = [&](vector<P> &v) -> void {
    int minx = INF, miny = INF;
    for(auto [x,y]: v) {
      minx = min(minx,x);
      miny = min(miny,y);
    }
    for(auto& [x,y]: v) { x -= minx; y -= miny; }
  };

  // pa[i][j] := i番目のポリオミノを (j+1)*90 度回転させたときの座標の集合
  vector pa(3,vector(4,vector<P>()));
  REP(k,3) REP(r,4) {
    rorate90(p[k]);
    REP(i,4) REP(j,4) if (p[k][i][j] == '#') pa[k][r].emplace_back(i,j);
    reset(pa[k][r]); // 左上に詰める
  }

  auto dfs = [&](auto self, int i, vector<vector<bool>> now) {
    if (i == 3) {
      REP(ni,4) REP(nj,4) if (!now[ni][nj]) return false;
      return true;
    }

    bool res = false;
    for(auto npa: pa[i]) {
      REP(ni,4) REP(nj,4) {
        auto nnow = now;
        bool ok = true;
        for(auto [x,y]: npa) {
          auto check = [&]() -> bool {
            int nx = x+ni, ny = y+nj;
            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) return false;
            if (nnow[nx][ny]) return false;
            return nnow[nx][ny] = true;
          };
          ok = ok && check();
        }
        res = res || (ok && self(self,i+1,nnow));
      }
    }
    return res;
  };

  bool ans = dfs(dfs,0,vector(4,vector<bool>(4)));
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}