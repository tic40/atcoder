#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector c(3,vector<int>(3));
  REP(i,3) REP(j,3) cin >> c[i][j];
  vector visited(3,vector<bool>(3));

  auto check1 = [&](int i, int j) {
    vector<int> b;
    REP(ti,3) {
      if (ti == i) continue;
      b.push_back(ti);
    }
    if (!visited[b[0]][j] || !visited[b[1]][j]) return true;
    return (c[b[0]][j] != c[b[1]][j]);
  };
  auto check2 = [&](int i, int j) {
    vector<int> b;
    REP(tj,3) {
      if (tj == j) continue;
      b.push_back(tj);
    }
    if (!visited[i][b[0]] || !visited[i][b[1]]) return true;
    return (c[i][b[0]] != c[i][b[1]]);
  };
  auto check3 = [&](int i, int j) {
    vector<int> b;
    bool ok = false;
    REP(ti,3) {
      if (ti == i && ti == j) { ok = true; continue; }
      b.push_back(ti);
    }
    if (!ok) return true;
    if (!visited[b[0]][b[0]] || !visited[b[1]][b[1]]) return true;
    return (c[b[0]][b[0]] != c[b[1]][b[1]]);
  };
  auto check4 = [&](int i, int j) {
    vector<int> b;
    bool ok = false;
    REP(ti,3) {
      if (ti == i && (2-ti) == j) { ok=true; continue;}
      b.push_back(ti);
    }
    if (!ok) return true;
    if (!visited[b[0]][2-b[0]] || !visited[b[1]][2-b[1]]) return true;
    return (c[b[0]][2-b[0]] != c[b[1]][2-b[1]]);
  };

  int ok_cnt = 0;
  auto dfs = [&](auto self, int cnt) -> void {
    if (cnt == 9) { ok_cnt++; return; }
    REP(ni,3) REP(nj,3) {
      if (visited[ni][nj]) continue;
      bool ok = check1(ni,nj) && check2(ni,nj) && check3(ni,nj) && check4(ni,nj);
      if (!ok) continue;
      visited[ni][nj]= true;
      self(self,cnt+1);
      visited[ni][nj]= false;
    }
  };

  REP(i,3) REP(j,3) {
    visited[i][j] = true;
    dfs(dfs,1);
    visited[i][j] = false;
  }

  double ans = ok_cnt / 362880.0;
  printf("%.10f\n",ans);
  return 0;
}