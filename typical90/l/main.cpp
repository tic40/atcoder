#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

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

const vector<pair<int,int>> moves = {
  { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }
};

int h,w,q;
bool used[2005][2005];

int get_hash(int x, int y) {
  return (x-1)*w+(y-1);
}

int main() {
  cin >> h >> w >> q;
  UnionFind uf(h*w);

  auto query1 = [&](int r, int c) {
    for(auto p: moves) {
      int sx = r + p.first, sy = c + p.second;
      if (!used[sx][sy]) continue;

      int h1 = get_hash(r,c);
      int h2 = get_hash(sx,sy);
      uf.unite(h1,h2);
    }
    used[r][c]=true;
  };

  auto query2 = [&](int ra, int ca, int rb, int cb) {
    int ok = false;
    if (used[ra][ca] && used[rb][cb]) {
      int h1 = get_hash(ra,ca);
      int h2 = get_hash(rb,cb);
      if (uf.same(h1,h2)) ok = true;
    }

    string ans = ok ? "Yes" : "No";
    cout << ans << endl;
  };

  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int r,c; cin >> r >> c;
      query1(r,c);
    } else {
      int ra,ca,rb,cb;
      cin >> ra >> ca >> rb >> cb;
      query2(ra,ca,rb,cb);
    }
  }

  return 0;
}