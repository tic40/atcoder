#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n, -1) {} // -1で初期化(負の場合をrootとし、この値で木の深さも表す)
  int root(int x) {
    if (d[x] < 0) return x; // 負の場合はroot
    return d[x] = root(d[x]); // 経路圧縮: 自身が親でないときは、親に設定する
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y]; // -1からさらに—1していくことで、-2,-3… となり木の深さを表現
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -d[root(x)]; /* 木の深さ */ }
};


using P = pair<int,int>;
int n,m;
vector<pair<int, P>> es; // pair<重み, 辺の両端>

void solve() {
  ll ans = 0;
  UnionFind uf(n);

  for(auto v: es) {
    int w = v.first; // 重み
    auto e = v.second; // 両端
    int a = e.first, b = e.second; // 両端a,b

    // w の重みが最大になる組合わせ数
    ans += ll(w) * uf.size(a)*uf.size(b);
    uf.unite(a,b);
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  REP(i,n-1) {
    int u,v,w;
    cin >> u >> v >> w;
    u--; v--;
    es.emplace_back(w, P(u,v));
  }
  // 重みを軽い順にソートする
  sort(es.begin(), es.end());

  solve();
  return 0;
}