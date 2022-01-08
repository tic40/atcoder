#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

struct UnionFind {
  vector<ll> d;
  UnionFind(ll n=0): d(n, -1) {} // -1で初期化(負の場合をrootとし、この値で木の深さも表す)
  ll root(ll x) {
    if (d[x] < 0) return x; // 負の場合はroot
    return d[x] = root(d[x]); // 経路圧縮: 自身が親でないときは、親に設定する
  }
  bool unite(ll x, ll y) {
    x = root(x); y = root(y);
    if (x == y) return false;

    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y]; // -1からさらに—1していくことで、-2,-3… となり木の深さを表現
    d[y] = x;
    return true;
  }
  bool same(ll x, ll y) { return root(x) == root(y); }
  ll size(ll x) { return -d[root(x)]; /* 木の深さを正の値で返す */ }
};

ll n,m;
vector<ll> a,b;

void solve() {
  vector<ll> ans(m); // 不便さ
  ans[0]=n*(n-1)/2; // 橋がどこにも無い状態の不便さ. Nから2個取り出す組み合わせ

  // 橋を消す操作ではなく、橋を逆順から追加していく操作で考える
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());

  UnionFind uf(n);

  REP(i,m-1) {
    // 連結済み
    if (uf.same(a[i],b[i])) { ans[i+1] = ans[i]; continue; }

    // 未連結
    ans[i+1] = ans[i] - uf.size(a[i]) * uf.size(b[i]);
    uf.unite(a[i],b[i]);
  }

  reverse(ans.begin(),ans.end()); // ansが逆順の操作で格納されているため、reverse
  REP(i,m) cout << ans[i] << endl;

  return;
}

int main() {
  cin >> n >> m;
  a.resize(m); b.resize(m);

  REP(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--; // 0-indexed
  }

  solve();
  return 0;
}