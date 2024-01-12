#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct WeightedUnionFind {
  vector<int> p; // 親へのリンク
  vector<ll> dif; // 親との差分
  WeightedUnionFind(int n): p(n,-1),dif(n) {}

  int root(int a) {
    if (p[a] < 0) return a;
    int b = p[a];
    p[a] = root(b);
    dif[a] += dif[b];
    return p[a];
  }
  bool merge(int a, int b, ll w) {
    root(a); root(b);
    w = w + dif[a] - dif[b];
    a = root(a);
    b = root(b);
    if (a == b) return w == 0;
    if (-p[a] < -p[b]) swap(a,b), w = -w;
    p[a] += p[b];
    p[b] = a;
    dif[b] = w;
    return true;
  }
};

int main() {
  int n,q; cin >> n >> q;

  vector<int> ans;
  WeightedUnionFind uf(n);
  REP(i,q) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    if (uf.merge(a,b,c)) ans.push_back(i+1);
  }

  for(auto v: ans) cout << v << " ";
  return 0;
}