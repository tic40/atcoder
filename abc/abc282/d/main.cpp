#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n);
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> col(n,-1);
  // cnt[i][j] := 連結成分i の 色0,1 の総数
  vector cnt(n, vector<int>(2));
  // bg[i] := i頂点が所属している連結成分の番号
  vector<int> bg(n);
  bool ok = true;
  REP(i,n) {
    if (col[i] != -1) continue;
    queue<int> que;

    col[i] = 0;
    que.push(i);

    while(que.size()) {
      int qi = que.front(); que.pop();
      bg[qi] = i;
      cnt[i][col[qi]]++;
      for (auto ni : g[qi]) {
        if (col[ni] != -1) {
          if (col[ni] == col[qi]) ok = false;
          continue;
        }
        col[ni] = 1 - col[qi];
        que.push(ni);
      }
    }
  }

  // 2部グラフでないので終了
  if (!ok) { cout << 0 << endl; return 0; }

  ll ans = 0;
  REP(i,n) {
    // 連結成分内で接続可能な数
    ans += cnt[bg[i]][1-col[i]] - (int)g[i].size();
    // 連結成分外で接続可能な数
    ans += n - (cnt[bg[i]][0] + cnt[bg[i]][1]);
  }

  cout << ans/2 << endl;
  return 0;
}