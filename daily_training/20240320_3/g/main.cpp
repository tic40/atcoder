#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

ll c2(ll n) { return n * (n-1) / 2; }

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int u,v; cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int>col(2e5,-1);
  vector<int>cnt(2);
  auto bfs = [&](int i) {
    queue<int> q;
    cnt = vector<int>(2);
    col[i] = 0;
    q.push(i);
    while(q.size()) {
      int qi = q.front(); q.pop();
      cnt[col[qi]]++;
      for (auto ni : g[qi]) {
        if (col[ni] != -1) {
          if (col[ni] == col[qi]) return false;
          continue;
        }
        col[ni] = 1 ^ col[qi];
        q.push(ni);
      }
    }
    return true;
  };

  ll ans = c2(n); // 全体の数
  ans -= m; // 全体の数からすでに接続している辺の分を減らす
  REP(i,n) {
    if (col[i] != -1) continue;
    // 2部グラフでないので終了
    if (!bfs(i)) { cout << 0 << endl; return 0; }

    // 同じ色同士は接続できないので減らす
    ans -= c2(cnt[0]);
    ans -= c2(cnt[1]);
  }

  cout << ans << endl;
  return 0;
}