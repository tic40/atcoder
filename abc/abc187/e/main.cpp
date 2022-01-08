#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,q;
vector<int> a,b;
vector<int> t,e;
vector<int> depth;
vector<ll> x, dp;
vector<vector<ll>> g;

// グラフの深さを求めるdfs
void depthDFS(int a, int d) {
  depth[a] = d;

  for (auto next: g[a]) {
    if (depth[next] != -1) continue;
    depthDFS(next, d+1);
  }

  return;
}

// 差分から実際の値を求めるdfs
void imosDFS(int a, ll now) {
  now += dp[a];
  dp[a] = now;

  for (auto next: g[a]) {
    if (depth[next] <= depth[a]) continue;
    imosDFS(next, now);
  }

  return;
}

void solve() {
  depth.resize(n,-1); // 未訪問初期値を-1にする
  g.resize(n); // グラフ
  dp.resize(n);

  REP(i,n) { // グラフ化
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  depthDFS(0,0); // 0を起点に深さを求める

  REP(i,q) { // クエリ処理
    int va = a[e[i]];
    int vb = b[e[i]];
    if (t[i] == 2) swap(va,vb);

    // 通る方がdepthが小さい場合
    if (depth[va] < depth[vb]) {
      dp[0] += x[i]; // 根(全体)に足す
      dp[vb] -= x[i]; // 通らない部分木は引く
    } else {
      dp[va] += x[i]; // 部分木に足す
    }
  }

  imosDFS(0,0);

  REP(i,n) cout << dp[i] << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);

  REP(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--; // 0-indexed
  }

  cin >> q;
  t.resize(q);
  e.resize(q);
  x.resize(q);

  REP(i,q) {
    cin >> t[i] >> e[i] >> x[i];
    e[i]--; // 0-indexed
  }

  solve();
  return 0;
}