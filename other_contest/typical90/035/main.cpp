#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

/*
  LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
  query(u,v): u と v の LCA を求める。計算量 O(logn)
  前処理: O(nlogn)時間, O(nlogn)空間
*/
struct LCA {
  vector<vector<int>> g; // graph
  vector<vector<int>> parent; // parent[k][u]:= u の 2^k 先の親
  vector<int> dist; // root からの距離
  vector<int> id;
  int n; // graph size
  int bits;
  LCA(vector<vector<int>> _g, int root = 0) { init(_g, root); }

  // 初期化
  void init(vector<vector<int>> _g, int root = 0) {
    g = _g;
    n = g.size();
    bits = 1;
    while ((1 << bits) < n) bits++;
    parent.resize(bits, vector<int>(n,-1));
    dist.resize(n);
    id.resize(n);
    int nid = 0;

    auto dfs = [&](auto self, int i, int p) -> void {
      parent[0][i] = p;
      id[i] = nid;
      nid++;
      for (auto v: g[i]) {
        if (v == p) continue;
        dist[v] = dist[i] + 1;
        self(self,v,i);
      }
    };

    dfs(dfs, root, -1);
    for(int i = 1; i < bits; i++) REP(j,n) {
      parent[i][j] = parent[i-1][parent[i-1][j]];
    }
  }

  // 頂点 u, v の LCA を求める
  int query(int u, int v) {
    if (dist[u] < dist[v]) swap(u, v); // u を深い方とする
		for (int i = bits - 1; i >= 0; i--) {
			if (dist[u] - dist[v] >= (1 << i)) u = parent[i][u];
		}
		if (u == v) return u;
		for (int i = bits - 1; i >= 0; --i) {
			if (parent[i][u] != parent[i][v]) {
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return parent[0][u];
  }
};

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int q; cin >> q;

  auto solve1 = [&]() {
    REP(_,q) {
      int k; cin >> k;
      vector<int> v(k);
      vector<bool> used(n);
      REP(j,k) {
        cin >> v[j]; v[j]--;
        used[v[j]] = true;
      }
      auto tree_dp = [&](auto self, int now, int pre) -> void {
        for(int i: g[now]) {
          if (i == pre) continue;
          self(self,i,now);
          used[now] = used[now] || used[i];
        }
      };

      tree_dp(tree_dp,v[0],-1);
      int ans = 0;
      REP(i,n) if (used[i]) ans++;
      ans--; // v[0] の分を引く
      cout << ans << endl;
    }
  };

  auto solve2 = [&]() {
    LCA l(g,0);
    REP(_,q) {
      int k; cin >> k;
      if (k != 2) return;
      int a,b; cin >> a >> b;
      a--; b--;
      cout << l.dist[a] + l.dist[b] - 2 * l.dist[l.query(a,b)] << endl;
    }
  };

  auto solve3 = [&]() {
    LCA l(g,0);
    REP(_,q) {
      int k; cin >> k;
      if (k != 3) return;
      int a,b,c; cin >> a >> b >> c;
      a--; b--; c--;
      int ans = l.dist[a] + l.dist[b] + l.dist[c];
      ans -= l.dist[l.query(a,b)];
      ans -= l.dist[l.query(b,c)];
      ans -= l.dist[l.query(a,c)];
      cout << ans << endl;
    }
  };

  auto solve4 = [&]() {
    LCA l(g,0);
    REP(_,q) {
      int k; cin >> k;
      vector<int> v(k);
      REP(i,k) { cin >> v[i]; v[i]--; }
      sort(v.begin(),v.end(),[&](int a, int b) {
        return l.id[a] < l.id[b];
      });
      int ans = 0;
      REP(i,k) {
        ans += l.dist[v[i]];
        ans -= l.dist[l.query(v[i], v[ (i+1)%k ])];
      }
      cout << ans << endl;
    }
  };

  // 小課題 1 解
  // solve1();
  // 小課題 2 解
  // solve2();
  // 小課題 3 解
  //solve3();
  // 完全解
  solve4();

  return 0;
}